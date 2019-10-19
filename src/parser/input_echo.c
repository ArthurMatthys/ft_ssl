/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_echo.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/19 11:20:37 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/19 11:52:34 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"

char	*get_res_echo(void)
{
	char	buff[BUFF_SIZE + 1];
	char	*ret;
	char	*tmp;

	ret = NULL;
	ft_bzero(buff, BUFF_SIZE + 1);
	while (read(0, buff, BUFF_SIZE) > 0)
	{
		tmp = ret;
		if (!ret)
			ret = ft_strjoin("./ft_ssl ", buff);
		else
			ret = ft_strjoin(ret, buff);
		free(tmp);
	}
	return (ret);
}
