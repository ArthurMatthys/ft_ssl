/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_stdin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/19 11:29:52 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 10:45:42 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"

static void		init_line(t_line_edit *line, const char *prompt,
		t_history **history)
{
	line->prompt = prompt;
	line->p_len = ft_strlen((char*)prompt);
	line->buff = NULL;
	line->size_buff = 0;
	line->actual = *history;
	write(1, line->prompt, line->p_len);
}

static void		delete_last_char(t_line_edit *line)
{
	if (!(line->size_buff))
		return ;
	line->buff[line->size_buff - 1] = '\0';
	line->size_buff--;
	refresh_line(line);
}

static void		add_char(t_line_edit *line, char c)
{
	line->buff = ft_realloc(line->buff, line->size_buff + 1);
	line->buff[line->size_buff] = c;
	line->size_buff += 1;
	refresh_line(line);
}

int				handle_stdin(const char *prompt, char **res,
		t_history **history)
{
	char		c;
	t_line_edit	line;

	init_line(&line, prompt, history);
	while (read(0, &c, 1 > 0))
	{
		if (c == CTRL_D || c == ENTER)
		{
			if (!line.size_buff)
			{
				free(line.buff);
				return (0);
			}
			*res = ft_strdup(line.buff);
			free(line.buff);
			return (line.size_buff);
		}
		else if (c == BACKSPACE)
			delete_last_char(&line);
		else if (c == START_KEYARROW)
			move_history(&line);
		else
			add_char(&line, c);
	}
	return (line.size_buff);
}
