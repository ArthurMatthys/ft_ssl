/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 15:58:32 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 09:37:25 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <sys/stat.h>
# include <fcntl.h>

# define FD_NOTFOUND -1
# define FD_NSTATS -2
# define FD_DIR -3

# define NB_CMD 7

typedef	void	(*t_handler)();

typedef struct	s_list_cmd
{
	char		*name;
	t_handler	handler;
	int			index;
}				t_list_cmd;

void			get_command(int argc, char **argv);
int				ssl_usage(void);
int				ssl_list_command(char *cmd);
int				error_open(char *str, char *cmd_name, int fd);
int				open_arg(char *str);
int				read_fd(t_alltypes *buff, int fd, int to_read);

#endif
