/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_hash.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:48:14 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 15:41:17 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_hash.h"

t_hash_cmd	g_hash_cmd[NB_HASH_FUNCTION] =
{
	{"md5", "MD5", &ft_md5_init, &ft_md5_update, &ft_md5_close, \
		{"-s", "-r", "-q", "-p"}, 64, 32, 4, 4, 8},
	{}
};

void	hash_init(t_hash_cmd cmd, t_hash_use *hash)
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

void	hash_destroy(t_hash_use *hash)
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

void	ssl_hash(int argc, char **argv, int index)
{
	t_hash_cmd	h_cmd;
	int			i;
	unsigned	flag;

	i = 2;
	flag = H_STRING;
	h_cmd = g_hash_cmd[index];
	while (i < argc || (argc == 2 && i <= argc))
	{
		i += find_flag(argc - i, argv + i, &flag, h_cmd);
		if ((flag & H_P) || argc == 2)
			ft_ssl_hash_routine(h_cmd, flag, C_STDIN, NULL);
		else if (i == argc && flag & H_S)
			ft_printf("-S SHOULD BE FOLLOWED BY A STRING\n");
		else if (i < argc)
			ft_ssl_hash_routine(h_cmd, flag, flag & H_S ? C_STRING : C_FILE,\
					argv[i]);
		update_flag(&flag);
		i++;
	}
}
