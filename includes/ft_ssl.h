/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/11 14:52:24 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/24 11:50:30 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdlib.h>
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

#include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>


# define T_S		1
# define T_R		2
# define T_Q		4
# define T_P		8
# define T_PDONE	16
# define T_TODEL	32
# define T_BADINPUT 64

# define NB_CMD		2
# define NB_FLAG_MAX	4

# define READ_SIZE 4096

typedef int			(*t_handler)();

typedef struct		s_cmd
{
	int				index;
	char			*name;
	char			*to_print;
	t_handler		handler;
	t_handler		parser;
	char			*flags[NB_FLAG_MAX];
	int				flag;
	int				nb_flag;
	int				nb_unsigned;
}					t_cmd;

typedef struct		s_arg
{
	char			*msg;
	t_cmd			*cmd;
	struct s_arg	*next;
	struct s_arg	*previous;
}					t_arg;

t_cmd g_cmd[NB_CMD];

int					ft_ssl_md5(t_arg *arguments);
int					ft_ssl_sha256(t_arg *arguments);
int					ssl_usage();
int					ssl_list_command(char *cmd);
int					ssl_handle_input(t_arg **arguments, int argc, char **argv);
int					ssl_handle_md5(t_arg *arguments, char **argv);
int					ft_ssl_md5_parser(t_arg *new_arg, char **argv, int *i, int argc);
int					read_file(t_arg *argument, size_t *size);
void				ft_memrev(unsigned char *ptr, int size);
void				print_struct(t_arg **arguments);
void				ft_ssl_md5_print(t_arg *argument, unsigned *sum, char *filename);
t_arg				*get_stdin(t_cmd *cmd);

#endif
