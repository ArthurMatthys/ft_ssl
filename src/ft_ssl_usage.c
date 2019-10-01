/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_usage.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:40:58 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 16:41:44 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

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
