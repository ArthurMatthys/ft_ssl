/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_stdin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/19 11:29:52 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/19 18:55:37 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"

int		handle_stdin(const char *prompt, char *res)
{
	char	c;

	ft_printf("%s", prompt);
	while (read(0, &c, 1))
	{

	}
	(void)res;
	return (0);
}
