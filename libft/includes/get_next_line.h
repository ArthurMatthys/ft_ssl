/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 12:27:35 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 13:30:03 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <unistd.h>

typedef struct		s_fd
{
	int				fd;
	int				len;
	char			*str;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(int const fd, char **tab);
t_fd				**get_fd(void);
void				free_fd(void);

#endif
