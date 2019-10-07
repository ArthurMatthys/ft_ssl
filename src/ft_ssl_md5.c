/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_md5.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 09:37:55 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 15:51:44 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl_hash.h"

t_hash_cst	g_hash_cst[64] = {
	{&f0, 0xd76aa478, 7, 0},
	{&f0, 0xe8c7b756, 12, 1},
	{&f0, 0x242070db, 17, 2},
	{&f0, 0xc1bdceee, 22, 3},
	{&f0, 0xf57c0faf, 7, 4},
	{&f0, 0x4787c62a, 12, 5},
	{&f0, 0xa8304613, 17, 6},
	{&f0, 0xfd469501, 22, 7},
	{&f0, 0x698098d8, 7, 8},
	{&f0, 0x8b44f7af, 12, 9},
	{&f0, 0xffff5bb1, 17, 10},
	{&f0, 0x895cd7be, 22, 11},
	{&f0, 0x6b901122, 7, 12},
	{&f0, 0xfd987193, 12, 13},
	{&f0, 0xa679438e, 17, 14},
	{&f0, 0x49b40821, 22, 15},
	{&f1, 0xf61e2562, 5, 1},
	{&f1, 0xc040b340, 9, 6},
	{&f1, 0x265e5a51, 14, 11},
	{&f1, 0xe9b6c7aa, 20, 0},
	{&f1, 0xd62f105d, 5, 5},
	{&f1, 0x02441453, 9, 10},
	{&f1, 0xd8a1e681, 14, 15},
	{&f1, 0xe7d3fbc8, 20, 4},
	{&f1, 0x21e1cde6, 5, 9},
	{&f1, 0xc33707d6, 9, 14},
	{&f1, 0xf4d50d87, 14, 3},
	{&f1, 0x455a14ed, 20, 8},
	{&f1, 0xa9e3e905, 5, 13},
	{&f1, 0xfcefa3f8, 9, 2},
	{&f1, 0x676f02d9, 14, 7},
	{&f1, 0x8d2a4c8a, 20, 12},
	{&f2, 0xfffa3942, 4, 5},
	{&f2, 0x8771f681, 11, 8},
	{&f2, 0x6d9d6122, 16, 11},
	{&f2, 0xfde5380c, 23, 14},
	{&f2, 0xa4beea44, 4, 1},
	{&f2, 0x4bdecfa9, 11, 4},
	{&f2, 0xf6bb4b60, 16, 7},
	{&f2, 0xbebfbc70, 23, 10},
	{&f2, 0x289b7ec6, 4, 13},
	{&f2, 0xeaa127fa, 11, 0},
	{&f2, 0xd4ef3085, 16, 3},
	{&f2, 0x04881d05, 23, 6},
	{&f2, 0xd9d4d039, 4, 9},
	{&f2, 0xe6db99e5, 11, 12},
	{&f2, 0x1fa27cf8, 16, 15},
	{&f2, 0xc4ac5665, 23, 2},
	{&f3, 0xf4292244, 6, 0},
	{&f3, 0x432aff97, 10, 7},
	{&f3, 0xab9423a7, 15, 14},
	{&f3, 0xfc93a039, 21, 5},
	{&f3, 0x655b59c3, 6, 12},
	{&f3, 0x8f0ccc92, 10, 3},
	{&f3, 0xffeff47d, 15, 10},
	{&f3, 0x85845dd1, 21, 1},
	{&f3, 0x6fa87e4f, 6, 8},
	{&f3, 0xfe2ce6e0, 10, 15},
	{&f3, 0xa3014314, 15, 6},
	{&f3, 0x4e0811a1, 21, 13},
	{&f3, 0xf7537e82, 6, 4},
	{&f3, 0xbd3af235, 10, 11},
	{&f3, 0x2ad7d2bb, 15, 2},
	{&f3, 0xeb86d391, 21, 9}
};

void		ft_md5_init(t_hash_cmd cmd, t_hash_use *hash)
{
	hash_init(cmd, hash);
	hash->registers[0].x32 = 0x67452301;
	hash->registers[1].x32 = 0xefcdab89;
	hash->registers[2].x32 = 0x98badcfe;
	hash->registers[3].x32 = 0x10325476;
}

static void	ft_md5_fct(t_hash_cst cst, t_alltypes *reg, t_blockx32 *block)
{
	unsigned	tmp;

	tmp = reg[1].x32 + rot_32(reg[0].x32 +
			cst.fct(reg) + cst.sines + block[cst.word].i,
			cst.rot);
	reg[0] = reg[3];
	reg[3] = reg[2];
	reg[2] = reg[1];
	reg[1].x32 = tmp;
}

int			ft_md5_update(t_hash_use *hash)
{
	int			i;
	int			j;
	t_alltypes	reg[4];

	i = 0;
	j = -1;
	while (++j < 4)
		reg[j] = hash->registers[j];
	while (i < 64)
	{
		ft_md5_fct(g_hash_cst[i], reg, (t_blockx32 *)hash->block);
		i++;
	}
	j = -1;
	while (++j < 4)
		hash->registers[j].x32 += reg[j].x32;
	return (1);
}

void		ft_md5_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done)
{
	if (h_done)
		ft_ssl_print_hash(h_cmd, h_use, flag);
	hash_destroy(h_use);
}
