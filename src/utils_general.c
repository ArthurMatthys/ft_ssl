/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_general.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/12 18:22:08 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/13 09:28:33 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int	ssl_usage(void)
{
	ft_putstr_fd("usage: ft_ssl commad [commad opts] [command args].\n", 2);
	return (0);
}

int	ssl_list_command(char *cmd)
{
	ft_putstr_fd("ft_ssl: Error \'", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\' is an invalid ", 2);
	ft_putstr_fd("command.\n", 2);
	ft_putstr_fd("\nStandard commands:\n", 2);
	ft_putstr_fd("\nMessage Digest commands:\nmd5\nsha256\n", 2);
	ft_putstr_fd("\nCipher commands:\n", 2);
	return (0);
}
