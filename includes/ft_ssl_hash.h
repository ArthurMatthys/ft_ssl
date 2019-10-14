/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_hash.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 17:07:24 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 09:34:20 by amatthys    ###    #+. /#+    ###.fr     */
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

# define REG_A 0
# define REG_B 1
# define REG_C 2
# define REG_D 3
# define REG_E 4
# define REG_F 5
# define REG_G 6
# define REG_H 7

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
	unsigned	endian;
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

typedef union	u_blockx32
{
	unsigned		i;
	unsigned char	c[4];
}				t_blockx32;

/*
** Global use
*/

void			ssl_hash(int argc, char **argv, t_hash_cmd h_cmd);

void			hash_init(t_hash_cmd cmd, t_hash_use *hash);
void			hash_destroy(t_hash_use *hash);

void			ft_ssl_hash_routine(t_hash_cmd h_cmd, int flag,
		int whcase, char *arg);
void			ft_ssl_print_hash(t_hash_cmd h_cmd, t_hash_use *hash,
		int flag, unsigned nb_reg);
void			print_block(t_hash_cmd h_cmd, t_hash_use *h_use);

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
** sha2
*/

size_t			ch(size_t reg_e, size_t reg_f, size_t reg_g);
size_t			maj(size_t reg_a, size_t reg_b, size_t reg_c);
void			rot_registers_sha(t_alltypes *reg, size_t *tmp);

/*
** sha 32 bits
*/

unsigned		smas0(unsigned word);
unsigned		smas1(unsigned word);
unsigned		bigs0(unsigned reg);
unsigned		bigs1(unsigned reg);
unsigned		leftrot_32(unsigned f, short g);
unsigned		rightrot_32(unsigned f, short g);
unsigned		rightshift_32(unsigned f, short g);
/*
** sha 224
*/

void			ft_sha224_init(t_hash_cmd cmd, t_hash_use *hash);
void			ft_sha224_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done);

/*
** sha256
*/

void			ft_sha256_init(t_hash_cmd cmd, t_hash_use *hash);
int				ft_sha256_update(t_hash_use *h_use);
void			ft_sha256_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done);

/*
** sha 64 bits
*/

size_t			smas0l(size_t word);
size_t			smas1l(size_t word);
size_t			bigs0l(size_t reg);
size_t			bigs1l(size_t reg);
size_t			leftrotl(size_t f, short g);
size_t			rightrotl(size_t f, short g);
size_t			rightshiftl(size_t f, short g);

/*
** sha384
*/

void			ft_sha384_init(t_hash_cmd cmd, t_hash_use *hash);
void			ft_sha384_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done);
/*
** sha512
*/

void			ft_sha512_init(t_hash_cmd cmd, t_hash_use *hash);
int				ft_sha512_update(t_hash_use *h_use);
void			ft_sha512_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done);

/*
** sha512
*/

void			ft_sha512224_init(t_hash_cmd cmd, t_hash_use *hash);
void			ft_sha512224_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done);

/*
** sha512
*/

void			ft_sha512256_init(t_hash_cmd cmd, t_hash_use *hash);
void			ft_sha512256_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done);

#endif
