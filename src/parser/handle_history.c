/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_history.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 09:01:39 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 12:39:24 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"

void		add_history(t_history *history, char *new_line)
{
	t_history	*new;

	if (!new_line)
		return ;
	ft_printf("new !\n");
	new = (t_history *)ft_memalloc_wrapper(sizeof(t_history));
	new->line = ft_strdup(new_line);
	new->next = NULL;
	new->previous = history;
	history = new;
}

static void	history_up(t_line_edit *line, int direction)
{
	ft_printf("\r\nyooooooo\r\n");
	if (!(line->actual->previous) && direction)
		return ;
	if (!(line->actual->next) && !direction)
		return ;
	if (direction)
		line->actual = line->actual->previous;
	else
		line->actual = line->actual->next;
	line->buff = line->actual->line;
	line->size_buff = ft_strlen(line->buff);
	refresh_line(line);
}

void		free_history(t_history *history)
{
	t_history	*curr;

	while (history)
	{
		curr = history;
		history = history->next;
		free(curr->line);
		free(curr);
	}
}

void		move_history(t_line_edit *line)
{
	char	seq[2];

	read(0, seq, 1);
	read(0, seq + 1, 1);
	ft_printf("yo\n");
	if (!line->actual)
		return ;
	if (*seq == MID_KEYARROW)
	{
		if (seq[1] == UPARROW)
			history_up(line, 1);
		else if (seq[1] == DOWNARROW)
			history_up(line, 0);
	}
}
