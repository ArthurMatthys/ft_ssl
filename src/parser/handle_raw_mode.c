/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_raw_mode.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/19 11:23:26 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/19 18:51:16 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"

struct	termios orig_termios;

int		disablerawmode()
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
		return (-1);
	return (0);
}

int		enablerawmode()
{
	if (tcgetattr(STDIN_FILENO, &orig_termios) == -1)
		return (-1);
	struct termios raw = orig_termios;

	tcgetattr(STDIN_FILENO, &raw);

	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 5;
	
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
		return (-1);
	return (0);
}
