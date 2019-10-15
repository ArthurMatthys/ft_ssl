/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_usage.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:40:58 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 13:12:41 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*g_dgst_cmd[] =
{"md5", "sha224", "sha256", "sha384", "sha512", "sha512224", "sha512256", NULL};

char	*g_std_cmd[] =
{NULL};

char	*g_cipher_cmd[] =
{NULL};

int			ssl_usage(void)
{
	ft_putstr_fd("usage: ft_ssl command [commad opts] [command args].\n",
			STD_ERR);
	return (0);
}

static void	print_cmd(char **lst)
{
	int i;

	i = 0;
	while (lst[i])
	{
		ft_printf("%-15s", lst[i]);
		if ((i && !(i % 4)) || !(lst[i + 1]))
			ft_putstr_fd("\n", STD_ERR);
		else
			ft_putstr_fd("\t", STD_ERR);
		i++;
	}
	ft_putstr_fd("\n", STD_ERR);
}

int			ssl_list_command(char *cmd)
{
	ft_putstr_fd("ft_ssl: Error \'", STD_ERR);
	ft_putstr_fd(cmd, STD_ERR);
	ft_putstr_fd("\' is an invalid ", STD_ERR);
	ft_putstr_fd("command.\n", STD_ERR);
	ft_putstr_fd("\nStandard commands:\n", STD_ERR);
	print_cmd(g_std_cmd);
	ft_putstr_fd("Message Digest commands:\n", STD_ERR);
	print_cmd(g_dgst_cmd);
	ft_putstr_fd("Cipher commands:\n", STD_ERR);
	print_cmd(g_cipher_cmd);
	return (0);
}

int			error_open(char *str, char *cmd_name, int fd)
{
	if (fd == FD_NOTFOUND)
	{
		ft_putstr_fd(cmd_name, STD_ERR);
		ft_putstr_fd(": ", STD_ERR);
		ft_putstr_fd(str, STD_ERR);
		ft_putstr_fd(": No such file or directory\n", STD_ERR);
	}
	else if (fd == FD_NSTATS)
		ft_putstr_fd("ERROR : Failed to get filedescriptor stats.\n", STD_ERR);
	else if (fd == FD_DIR)
	{
		ft_putstr_fd(cmd_name, STD_ERR);
		ft_putstr_fd(": ", STD_ERR);
		ft_putstr_fd(str, STD_ERR);
		ft_putstr_fd(": Is a directory\n", STD_ERR);
	}
	return (0);
}
