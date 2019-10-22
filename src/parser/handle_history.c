/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_history.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 09:01:39 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 10:56:59 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"

void		add_history(t_history **history, char *new_line)
{
	t_history	*new;
	t_history	*back;

	if (!new_line)
		return ;
	back = (*history)->previous;
	new = (t_history *)ft_memalloc_wrapper(sizeof(t_history));
	new->line = ft_strdup(new_line);
	new->next = *history;
	new->previous = back;
	(*history)->previous = new;
	back->next = new;
	*history = new->next;
}

static void	history_up(t_line_edit *line, int direction)
{
	if ((!(line->actual->previous) && direction)
			|| (!(line->actual->next) && !direction))
		return ;
	if (direction)
		line->actual = line->actual->previous;
	else
		line->actual = line->actual->next;
	if (line->buff)
		free(line->buff);
	if (line->actual->line)
		line->buff = ft_strdup(line->actual->line);
	else
		line->buff = NULL;
	line->size_buff = line->buff ? ft_strlen(line->buff) : 0;
	refresh_line(line);
}

void		free_history(t_history *history)
{
	t_history	*curr;

	while (history)
	{
		curr = history;
		history = history->previous;
		if (curr->line)
			ft_memdel((void**)&curr->line);
		free(curr);
	}
}

void		move_history(t_line_edit *line)
{
	char	seq[2];

	read(0, seq, 1);
	read(0, seq + 1, 1);
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
