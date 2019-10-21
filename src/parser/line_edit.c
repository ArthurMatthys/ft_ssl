/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_edit.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 09:53:55 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 11:52:47 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"

static void	init_print(t_to_write *print)
{
	print->str = NULL;
	print->size = 0;
}

static void free_print(t_to_write *print)
{
	free(print->str);
}

static void	print_append(t_to_write *print, char *str, size_t size)
{
	char	*new;

	if (print->str)
	{
		ft_printf("%s", print->str);
		ft_printf("%d", print->size);
		ft_printf("%d", size);
		new = ft_strjoin(print->str, str);
		free(print->str);
	}
	else
		new = ft_memalloc_wrapper(size);
	if (!new)
		return ;
	ft_memcpy(new + print->size, str, size);
	print->str = new;
	print->size += size;
}

void		refresh_line(t_line_edit *line)
{
	char		seq[64];
	char		*tmp;
	t_to_write	to_print;

	init_print(&to_print);
	ft_strcpy(seq, "\r");
	print_append(&to_print, seq, ft_strlen(seq));
	print_append(&to_print, (char*)line->prompt, line->p_len);
	print_append(&to_print, line->buff, line->size_buff);
	ft_strcpy(seq, "\x1b[0K");
	print_append(&to_print, seq, ft_strlen(seq));
	ft_strcpy(seq, "\r\x1b[");
	tmp = ft_itoa(line->p_len + line->size_buff);
	ft_strcat(seq, tmp);
	free(tmp);
	ft_strcat(seq, "C");
	print_append(&to_print, seq, ft_strlen(seq));
	write(1, to_print.str, to_print.size);
	free_print(&to_print);
}
