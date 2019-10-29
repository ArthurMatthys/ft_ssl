/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stdin_to_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 11:29:58 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 15:52:16 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"
#include "../../includes/ft_ssl.h"

static t_history	*init_history(void)
{
	t_history	*last;
	t_history	*first;

	last = (t_history *)ft_memalloc_wrapper(sizeof(t_history));
	first = (t_history *)ft_memalloc_wrapper(sizeof(t_history));
	last->next = first;
	first->previous = last;
	return (first);
}

static char			*string_to_argv(char *input)
{
	char	*tmp;

	tmp = input;
	input = ft_strjoin("./ft_ssl ", input);
	free(tmp);
	return (input);
}

void				stdin_to_cmd(void)
{
	char		*input;
	char		**new_argv;
	int			i;
	t_history	*history;

	history = init_history();
	while ((input = read_line("ft_ssl>", &history)))
	{
		i = 0;
		input = remove_nl(input);
		add_history(&history, input);
		input = string_to_argv(input);
		ft_printf("input : |%s|\n", input);
		new_argv = stdin_to_argv(&input);
		while (new_argv[i])
			i++;
		get_command(i, new_argv, new_argv[1]);
		free(input);
		ft_freetab(new_argv);
	}
	free_history(history);
}
