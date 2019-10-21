/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_history.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 09:01:39 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 11:36:52 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"

t_history	**get_history(void)
{
	static t_history	*lst = NULL;

	return (&lst);
}

void		add_history(t_line_edit *line)
{
	t_history	*new;
	t_history	**all;

	all = get_history();
	if (!line->size_buff)
		return ;
	ft_printf("new !\n");
	new = (t_history *)ft_memalloc_wrapper(sizeof(t_history));
	new->line = ft_strdup(line->buff);
	new->next = NULL;
	new->previous = *(line->history);
	*all = new;
}

static void	history_up(t_line_edit *line, int direction)
{
	ft_printf("\r\nyooooooo\r\n");
	if (!(line->actual->previous))
		return ;
	if (direction)
		line->actual = line->actual->previous;
	else
		line->actual = line->actual->next;
	line->buff = line->actual->line;
	line->size_buff = ft_strlen(line->buff);
	refresh_line(line);
}

void		free_history(void)
{
	t_history	**lst;
	t_history	*curr;

	lst = get_history();
	while (lst && *lst)
	{
		curr = *lst;
		*lst = (*lst)->next;
		free(curr->line);
		free(curr);
	}
	ft_memdel((void **)lst);
	*lst = NULL;
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
