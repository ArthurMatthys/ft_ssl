/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_hash.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 17:07:24 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 15:54:17 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_HASH_H
# define FT_SSL_HASH_H

# include "ft_ssl.h"

# define NB_HASH_FUNCTION 7
# define NB_FLAG_HASH 4

# define H_S (1 << 0)
# define H_R (1 << 1)
# define H_Q (1 << 2)
# define H_P (1 << 3)
# define H_PDONE (1 << 4)
# define H_STRING (1 << 5)

# define C_STDIN 1
# define C_FILE 2
# define C_STRING 3

typedef struct	s_hash_cmd
{
	char		*cmd;
	char		*to_print;
	t_handler	init;
	int			(*update)();
	t_handler	close;
	char		flag_list[4][3];
	unsigned	len_block;
	unsigned	nb_register;
	unsigned	size_register;
	unsigned	size_len;
}				t_hash_cmd;

typedef struct	s_hash_use
{
	t_alltypes	len_msg;
	t_alltypes	*block;
	t_alltypes	*registers;
	char		*arg;
}				t_hash_use;

typedef unsigned (*t_fct)();

typedef struct	s_hash_cst
{
	t_fct		fct;
	unsigned	sines;
	unsigned	rot;
	unsigned	word;

}				t_hash_cst;

typedef union	s_blockx32
{
	unsigned		i;
	unsigned char	c[4];
}				t_blockx32;

t_hash_cmd	g_hash_cmd[NB_HASH_FUNCTION];

/*
** Global use
*/

void			hash_init(t_hash_cmd cmd, t_hash_use *hash);
void			hash_destroy(t_hash_use *hash);

void			ft_ssl_hash_routine(t_hash_cmd h_cmd, int flag,
		int whcase, char *arg);
void			ft_ssl_print_hash(t_hash_cmd h_cmd, t_hash_use *hash,
		int flag);
void			print_block(t_hash_cmd h_cmd, t_hash_use *h_use);


unsigned		leftrot_32(unsigned f, short g);
unsigned		rightrot_32(unsigned f, short g);
unsigned		rightshift_32(unsigned f, short g);
void			ft_ssl_load_registers(t_alltypes *dst,
		t_alltypes *src, unsigned nbr);
void			ft_ssl_add_registers(t_alltypes *dst,
		t_alltypes *src, unsigned nbr);


/*
** MD5
*/

void			ft_md5_init(t_hash_cmd cmd, t_hash_use *hash);
int				ft_md5_update(t_hash_use *h_use);
void			ft_md5_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done);

uint32_t		f0(t_alltypes *abcd);
uint32_t		f1(t_alltypes *abcd);
uint32_t		f2(t_alltypes *abcd);
uint32_t		f3(t_alltypes *abcd);

/*
** sha256
*/

void			ft_sha256_init(t_hash_cmd cmd, t_hash_use *hash);
int				ft_sha256_update(t_hash_use *h_use);
void			ft_sha256_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done);


/*
** sha 64 bytes
*/

unsigned 	s0_32(unsigned *words, int index);
unsigned 	s1_32(unsigned *words, int index);
unsigned 	S0_32(unsigned reg);
unsigned 	S1_32(unsigned reg);


/*
** sha512
*/

void			ft_sha512_init(t_hash_cmd cmd, t_hash_use *hash);
int				ft_sha512_update(t_hash_use *h_use);
void			ft_sha512_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done);



#endif
