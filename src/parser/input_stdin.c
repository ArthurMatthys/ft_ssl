/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_stdin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/19 11:29:52 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 11:30:09 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"

static void		init_line(t_line_edit *line, char *str, const char *prompt)
{
	line->prompt = prompt;
	line->p_len = ft_strlen((char*)prompt);
	if (str)
	{
		line->buff = str;
		line->size_buff = ft_strlen(str);
	}
	else
	{
		line->buff = NULL;
		line->size_buff = 0;
	}
	line->history = get_history();
	line->actual = *(line->history); 
	while (line->history && *(line->history))
	{
		ft_printf("%s\n", (*(line->history))->line);
		*(line->history) = (*(line->history))->previous;
	}
}

static void		delete_last_char(t_line_edit *line)
{
	if (!(line->size_buff))
		return;
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

int		handle_stdin(const char *prompt, char **res)
{
	char	c;
	int		nread;
	t_line_edit	line;

	init_line(&line, *res, prompt);
	write(1, line.prompt, line.p_len);
	while (1)
	{
		nread = read(0, &c, 1);
		if (nread <= 0)
			return (line.size_buff);
		else if (c == CTRL_D || c == ENTER)
		{
			if (!line.size_buff)
				return (0);
			add_history(&line);
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
	return (0);
}
