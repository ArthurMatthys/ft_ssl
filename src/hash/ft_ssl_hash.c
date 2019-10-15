/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_hash.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:48:14 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 13:09:34 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_hash.h"

void		hash_init(t_hash_cmd cmd, t_hash_use *hash)
{
	hash->registers = (t_alltypes *)ft_memalloc_wrapper(sizeof(char) *
			cmd.nb_register * cmd.size_register);
	hash->block = (t_alltypes *)ft_memalloc_wrapper(sizeof(char) *
			cmd.len_block);
	ft_bzero(hash->registers, cmd.nb_register * cmd.size_register);
	ft_bzero(hash->block, cmd.len_block);
	hash->arg = NULL;
	hash->len_msg.x128 = 0;
}

void		hash_destroy(t_hash_use *hash)
{
	ft_memdel((void *)&hash->registers);
	ft_memdel((void *)&hash->block);
}

static void	update_flag(unsigned *flag)
{
	if (*flag & H_P)
		*flag |= H_PDONE;
	if (!(*flag & H_S) && !(*flag & H_P))
		*flag -= (*flag & H_STRING);
	*flag &= (H_R | H_Q | H_PDONE | H_STRING);
}

static int	find_flag(int argc, char **argv, unsigned *flag, t_hash_cmd h_cmd)
{
	int		j;
	int		i;

	i = 0;
	while (i < argc)
	{
		j = *flag & H_STRING ? 0 : 1;
		while (j < NB_FLAG_HASH)
		{
			if (ft_strequ(argv[i], h_cmd.flag_list[j]))
				break ;
			j++;
		}
		if (j == NB_FLAG_HASH)
			return (i);
		*flag |= (1 << j);
		if (j == 3)
			return (i);
		i++;
		if (!j)
			return (i);
	}
	return (i);
}

void		ssl_hash(int argc, char **argv, t_hash_cmd h_cmd)
{
	int			i;
	int			nbr_done;
	unsigned	flag;

	i = 1;
	nbr_done = 0;
	flag = H_STRING;
	while (++i < argc || (argc == 2 && i <= argc))
	{
		i += find_flag(argc - i, argv + i, &flag, h_cmd);
		if (((flag & H_P) || argc == 2) && ++nbr_done)
			ft_ssl_hash_routine(h_cmd, flag, C_STDIN, NULL);
		else if (i == argc && flag & H_S && ++nbr_done)
		{
			ft_putstr_fd(h_cmd.cmd, 2);
			ft_putstr_fd(": option requires an argument -- s\n", 2);
			ssl_usage();
		}
		else if (i < argc && ++nbr_done)
			ft_ssl_hash_routine(h_cmd, flag, flag & H_S ? C_STRING : C_FILE,
					argv[i]);
		update_flag(&flag);
	}
	if (!nbr_done)
		ft_ssl_hash_routine(h_cmd, flag, C_STDIN, NULL);
}
