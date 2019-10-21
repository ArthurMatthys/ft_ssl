/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stdin_to_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 11:29:58 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 12:38:57 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"
#include "../../includes/ft_ssl.h"

static char	*string_to_argv(char *input)
{
	char	*tmp;

	tmp = input;
	input = ft_strjoin("./ft_ssl ", input);
	free(tmp);
	return (input);
}

void	stdin_to_cmd(void)
{
	char	*input;
	char	**new_argv;
	int		i;
	t_history	*history;

	i = 0;
	history = NULL;
	while ((input = read_line("ft_ssl>", history)))
	{
		input = remove_nl(input);
		add_history(history, input);
		input = string_to_argv(input);
		new_argv = stdin_to_argv(&input);
		while (new_argv[i])
			i++;
		get_command(i, new_argv, new_argv[1]);
		free(input);
		ft_freetab(new_argv);
	}
	free_history(history);
}
/*
**void	stdin_to_cmd(void)
**{
**	char	*buff;
**	char	**new_argv;
**	char	*tmp;
**	int		i;
**
**	enableRawMode();
**	ft_printf("ft_ssl>");
**	while (get_next_line(0, &buff) > 0)
**	{
**		i = 0;
**		if (ft_strcmp(buff, "q\n"))
**			exit(0);
**		tmp = ft_strjoin("./ft_ssl ", buff);
**		new_argv = ft_strsplit(tmp, ' ');
**		while (new_argv[i])
**			i++;
**		free(tmp);
**		free(buff);
**		buff = NULL;
**		get_command(i, new_argv, new_argv[1]);
**		ft_freetab(new_argv);
**		ft_printf("ft_ssl>");
**	}
**	free_fd();
**	if (buff)
**		free(buff);
**}
*/
