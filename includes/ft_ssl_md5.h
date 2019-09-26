/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_md5.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/15 15:26:08 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/20 15:52:02 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_SSL_MD5_H
# define FT_SSL_MD5_H

# include <stdlib.h>
# include "ft_ssl.h"

# define A0		0x67452301
# define B0		0xefcdab89
# define C0		0x98badcfe
# define D0		0x10325476

# define SIZE_BLOCK	512
# define LEN_BYTES	8

typedef union	u_block
{
	unsigned char	c[64];
	unsigned		i[64 / sizeof(int)];
	size_t			s[64 / sizeof(size_t)];
}				t_block;

typedef union	u_digest
{
	unsigned		i;
	unsigned char	c[4];
}				t_digest;

unsigned		f0(unsigned *abcd);
unsigned		f1(unsigned *abcd);
unsigned		f2(unsigned *abcd);
unsigned		f3(unsigned *abcd);

typedef unsigned	(*dgstfct)(unsigned *);

unsigned int	g_k[64];

int				g_s0[4];
int				g_s1[4];
int				g_s2[4];
int				g_s3[4];
int				*g_s[4];

dgstfct g_fct[4];
int		g_multiply[4];
int		g_add[4];

#endif
