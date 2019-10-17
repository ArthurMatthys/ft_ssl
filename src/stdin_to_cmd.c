/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stdin_to_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 11:29:58 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 11:32:02 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../libft/includes/get_next_line.h"

void	stdin_to_cmd(void)
{
	char	*buff;
	char	**new_argv;
	char	*tmp;
	int		i;

	ft_printf("ft_ssl>");
	while (get_next_line(0, &buff) > 0)
	{
		i = 0;
		tmp = ft_strjoin("./ft_ssl ", buff);
		new_argv = ft_strsplit(tmp, ' ');
		while (new_argv[i])
			i++;
		free(tmp);
		free(buff);
		buff = NULL;
		get_command(i, new_argv, new_argv[1]);
		ft_freetab(new_argv);
		ft_printf("ft_ssl>");
	}
	free_fd();
	if (buff)
		free(buff);
}
