/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_usage.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:40:58 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 18:45:20 by amatthys    ###    #+. /#+    ###.fr     */
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
			STDERR);
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
			ft_putstr_fd("\n", STDERR);
		else
			ft_putstr_fd("\t", STDERR);
		i++;
	}
	ft_putstr_fd("\n", STDERR);
}

int			ssl_list_command(char *cmd)
{
	ft_putstr_fd("ft_ssl: Error \'", STDERR);
	ft_putstr_fd(cmd, STDERR);
	ft_putstr_fd("\' is an invalid ", STDERR);
	ft_putstr_fd("command.\n", STDERR);
	ft_putstr_fd("\nStandard commands:\n", STDERR);
	print_cmd(g_std_cmd);
	ft_putstr_fd("Message Digest commands:\n", STDERR);
	print_cmd(g_dgst_cmd);
	ft_putstr_fd("Cipher commands:\n", STDERR);
	print_cmd(g_cipher_cmd);
	return (0);
}

int			error_open(char *str, char *cmd_name, int fd)
{
	if (fd == FD_NOTFOUND)
	{
		ft_putstr_fd(cmd_name, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putstr_fd(str, STDERR);
		ft_putstr_fd(": No such file or directory\n", STDERR);
	}
	else if (fd == FD_NSTATS)
		ft_putstr_fd("ERROR : Failed to get filedescriptor stats.\n", STDERR);
	else if (fd == FD_DIR)
	{
		ft_putstr_fd(cmd_name, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putstr_fd(str, STDERR);
		ft_putstr_fd(": Is a directory\n", STDERR);
	}
	return (0);
}
