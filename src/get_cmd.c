/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_cmd.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:05:59 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/02 09:56:40 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

const t_list_cmd g_list_cmd[NB_CMD] = 
{
	{"md5", &ssl_hash, 0},
	{"sha256", &ssl_hash, 1}
};


void	get_command(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < NB_CMD)
	{
		if (ft_strequ(argv[1], g_list_cmd[i].name))
		{
			g_list_cmd[i].handler(argc, argv, i);
			return;
		}
		i++;
	}
	ssl_list_command(argv[1]);
}
