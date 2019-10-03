/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 15:58:32 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/02 08:44:20 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# define NB_CMD 2

typedef	void	(*t_handler)();

typedef struct	s_list_cmd
{
	char		*name;
	t_handler	handler;
	int			index;
}				t_list_cmd;


void	get_command(int argc, char **argv);
int		ssl_usage(void);
int		ssl_list_command(char *cmd);

void	ssl_hash(int argc, char **argv, int index);

#endif
