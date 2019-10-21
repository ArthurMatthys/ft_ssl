/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_stdin.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/19 10:34:33 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 11:11:24 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_STDIN_H
# define FT_SSL_STDIN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <ctype.h>
# include <errno.h>
# include <stdlib.h>
# include <termios.h>

# define C_SQUOTE (1 << 0)
# define C_DQUOTE (1 << 1)
# define C_BQUOTE (1 << 2)

# define CTRL_D 4
# define ENTER 13
# define BACKSPACE 127
# define START_KEYARROW 27
# define MID_KEYARROW 91
# define UPARROW 65
# define DOWNARROW 66

typedef struct		s_history
{
	char		*line;
	struct s_history	*previous;
	struct s_history	*next;
}					t_history;

typedef struct		s_to_write
{
	char		*str;
	size_t		size;
}					t_to_write;

typedef struct		s_line_edit
{
	char		*buff;
	size_t		size_buff;
	const char	*prompt;
	size_t		p_len;
	t_history	*actual;
	t_history	**history;
}					t_line_edit;

int		enablerawmode(void);
int		disablerawmode(void);
int		handle_stdin(const char *prompt, char **res);

char	*remove_nl(char *input);
char	**stdin_to_argv(char **input);
char	*get_res_echo(void);
char	*read_line(const char *prompt);

int		clean_stdin(char **input);

t_history	**get_history(void);
void	add_history(t_line_edit *line);
void	move_history(t_line_edit *line);
void	free_history(void);

void	refresh_line(t_line_edit *line);
#endif
