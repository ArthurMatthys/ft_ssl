/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_hash.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 17:07:24 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 09:31:52 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_HASH_H
# define FT_SSL_HASH_H

# include "ft_ssl.h"

# define NB_HASH_FUNCTION 2

# define H_S (1 << 0)
# define H_R (1 << 1)
# define H_Q (1 << 2)
# define H_P (1 << 3)
# define H_PDONE (1 << 4)
# define H_STRING (1 << 5)

typedef struct	s_hash_cmd
{
	char		*to_print;
	t_handler	init;
	t_handler	update;
	t_handler	close;
	char		flag_list[4][2];
	unsigned	flag;
	unsigned	len_block;
	unsigned	len_output;
	unsigned	nb_register;
}				t_hash_cmd;

typedef struct	s_hash_use
{
	size_t		len_msg;
	unsigned	*block;
	unsigned	*registers;
}				t_hash_use

t_hash_cmd	g_hash_cmd[NB_HASH_FUNCTION];

/*
 * MD5
*/

void	ft_md5_init();
void	ft_md5_update();
void	ft_md5_end();

#endif
