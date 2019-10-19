/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_stdin.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/19 10:34:33 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/19 18:50:59 by amatthys    ###    #+. /#+    ###.fr     */
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

int		enablerawmode(void);
int		disablerawmode(void);
int		handle_stdin(const char *promt, char *res);

char	*remove_nl(char *input);
char	**stdin_to_argv(char **input);
char	*get_res_echo(void);
char	*read_line(const char *prompt);

int		clean_stdin(char **input);
#endif
