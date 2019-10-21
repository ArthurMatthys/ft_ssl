/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dispatcher.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/19 11:28:31 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 11:24:42 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"

char	*read_line(const char *prompt)
{
	int		read;
	char	*res;

	res = NULL;
	if (!isatty(STDIN))
	{
		res = get_res_echo();
		read = 0;
		return (res);
	}
	else
	{
		if (enablerawmode() == -1)
			return (NULL);
		read = handle_stdin(prompt, &res);
		free_history();
		if (read < 0)
		{
			ft_putstr_fd("Failed to malloc", 2);
			exit(1);
		}
		if (disablerawmode() == -1)
			ft_memdel((void **)&res);
		return (res);
	}
}
