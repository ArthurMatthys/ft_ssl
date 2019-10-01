/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ssl_hash.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:48:14 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 09:10:39 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_hash.h"

t_hash_cmd	g_hash_cmd[NB_HASH_FUNCTION] =
{
	{"MD5", &ft_md5_init, &ft_md5_update, &ft_md5_end, \
		{"-s", "-r", "-q", "-p"}, 0}	
};

void	ssl_hash(int argc, char **argv, int index)
{
	t_hash_cmd	h_cmd;

	h_cmd = g_hash_cmd[index]
	(void)argc;
	(void)argv;
	ft_printf("Great job\n");
}
