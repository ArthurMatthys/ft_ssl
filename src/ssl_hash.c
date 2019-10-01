/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ssl_hash.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:48:14 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 17:49:09 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_hash.h"

t_hash_cmd	g_hash_cmd[NB_HASH_FUNCTION] =
{
	{"MD5", &ft_md5_init, &ft_md5_update, &ft_md5_close, \
		{"-s", "-r", "-q", "-p"}, 64, 32, 4}	
};

void	hash_init(t_hash_cmd cmd, t_hash_use *hash)
{
	hash->registers = ft_memalloc_wrapper(sizeof(unsigned) * cmd.nb_register);
	hash->block = ft_memalloc_wrapper(sizeof(unsigned) * cmd.len_block);
	ft_bzero(hash->block, cmd.len_block);
}

void	hash_destroy(t_hash_use *hash)
{
	ft_memdel((void *)&hash->registers);
	ft_memdel((void *)&hash->block);
}

//static void	du_hash(t_hash_cmd *cmd, t_hash_use hash)
//{
//	(void)cmd;
//	(void)hash;
//}

static void	update_flag(unsigned *flag)
{
	if (*flag & H_P)
		*flag |= H_PDONE;
	if (!(*flag & H_S))
		*flag -= (*flag & H_STRING);
	*flag &= (H_R | H_Q | H_PDONE | H_STRING);
}

static void	find_flag(int argc, char **argv, int *index, unsigned *flag, t_hash_cmd h_cmd)
{
	int		j;

	while (*index < argc)
	{
		j = 0;
		while (j < NB_FLAG_HASH)
		{
			if (ft_strequ(argv[*index], h_cmd.flag_list[j]))
				break;
			j++;
		}
		if (j == NB_FLAG_HASH)
			return;
		*flag |= (1 << j);
		ft_printf("arg -> %s\tj -> %d\tflag -> %u\n", argv[*index], j, *flag);
		(*index)++;
		if (!j || j == 3)
			return;
	}
}

void	ssl_hash(int argc, char **argv, int index)
{
	t_hash_cmd	h_cmd;
	t_hash_use	h_use;
	int			i;
	unsigned	flag;

	i = 2;
	flag = H_STRING;
	h_cmd = g_hash_cmd[index];
	while (i < argc || (argc == 2 && i <= argc))
	{
		h_cmd.init(h_cmd, &h_use);	
		find_flag(argc, argv, &i, &flag, h_cmd);
		ft_printf("flag : %u\tindex -> %d\n", flag, i);
		if (flag & H_P || argc == 2)
			ft_printf("GJ : FOUND A -p");
		else if (flag & H_S && (i == argc))
			ft_printf("-S SHOULD BE FOLLOWED BY A STRING");
		else if (i == argc)
			;
		else
			ft_printf("nice, you've got an agument");
			//do_routine(argv[i], flag, h_use);
		h_cmd.close(&h_use);
		update_flag(&flag);
		i++;
	}
}
