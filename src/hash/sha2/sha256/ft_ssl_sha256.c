/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_sha256.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 16:42:23 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 09:39:43 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_hash.h"

unsigned	g_sha256_k[64] =
{
	0x428a2f98,
	0x71374491,
	0xb5c0fbcf,
	0xe9b5dba5,
	0x3956c25b,
	0x59f111f1,
	0x923f82a4,
	0xab1c5ed5,
	0xd807aa98,
	0x12835b01,
	0x243185be,
	0x550c7dc3,
	0x72be5d74,
	0x80deb1fe,
	0x9bdc06a7,
	0xc19bf174,
	0xe49b69c1,
	0xefbe4786,
	0x0fc19dc6,
	0x240ca1cc,
	0x2de92c6f,
	0x4a7484aa,
	0x5cb0a9dc,
	0x76f988da,
	0x983e5152,
	0xa831c66d,
	0xb00327c8,
	0xbf597fc7,
	0xc6e00bf3,
	0xd5a79147,
	0x06ca6351,
	0x14292967,
	0x27b70a85,
	0x2e1b2138,
	0x4d2c6dfc,
	0x53380d13,
	0x650a7354,
	0x766a0abb,
	0x81c2c92e,
	0x92722c85,
	0xa2bfe8a1,
	0xa81a664b,
	0xc24b8b70,
	0xc76c51a3,
	0xd192e819,
	0xd6990624,
	0xf40e3585,
	0x106aa070,
	0x19a4c116,
	0x1e376c08,
	0x2748774c,
	0x34b0bcb5,
	0x391c0cb3,
	0x4ed8aa4a,
	0x5b9cca4f,
	0x682e6ff3,
	0x748f82ee,
	0x78a5636f,
	0x84c87814,
	0x8cc70208,
	0x90befffa,
	0xa4506ceb,
	0xbef9a3f7,
	0xc67178f2
};

void		ft_sha256_init(t_hash_cmd cmd, t_hash_use *hash)
{
	hash_init(cmd, hash);
	hash->registers[REG_A].x32 = 0x6a09e667;
	hash->registers[REG_B].x32 = 0xbb67ae85;
	hash->registers[REG_C].x32 = 0x3c6ef372;
	hash->registers[REG_D].x32 = 0xa54ff53a;
	hash->registers[REG_E].x32 = 0x510e527f;
	hash->registers[REG_F].x32 = 0x9b05688c;
	hash->registers[REG_G].x32 = 0x1f83d9ab;
	hash->registers[REG_H].x32 = 0x5be0cd19;
}

static void	ft_sha256_update_inner(t_alltypes *reg, unsigned *block, unsigned i)
{
	size_t	tmp[2];

	tmp[0] = reg[REG_H].x32 + bigs1(reg[REG_E].x32) + ch(reg[REG_E].x32,
			reg[REG_F].x32, reg[REG_G].x32) + g_sha256_k[i] + block[i];
	tmp[1] = bigs0(reg[REG_A].x32) +
		maj(reg[REG_A].x32, reg[REG_B].x32, reg[REG_C].x32);
	rot_registers_sha(reg, tmp);
}

int			ft_sha256_update(t_hash_use *hash)
{
	unsigned	block[64];
	t_alltypes	reg[8];
	unsigned	i;
	unsigned	*cpy;

	cpy = (unsigned *)hash->block;
	i = -1;
	while (++i < 16)
		block[i] = *((unsigned *)ft_memrev(&(cpy[i]), 4));
	i = 15;
	while (++i < 64)
		block[i] = block[i - 16] + smas0(block[i - 15])
			+ block[i - 7] + smas1(block[i - 2]);
	ft_ssl_load_registers(reg, hash->registers, 8);
	i = -1;
	while (++i < 64)
		ft_sha256_update_inner(reg, block, i);
	ft_ssl_add_registers(hash->registers, reg, 8);
	return (1);
}

void		ft_sha256_close(t_hash_cmd h_cmd,
		t_hash_use *h_use, int flag, int h_done)
{
	if (h_done)
		ft_ssl_print_hash(h_cmd, h_use, flag, 32);
	hash_destroy(h_use);
}
