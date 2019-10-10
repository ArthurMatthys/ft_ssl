/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_sha512.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 16:42:48 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 09:13:32 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/ft_ssl_hash.h"

void			ft_sha512_init(t_hash_cmd cmd, t_hash_use *hash)
{
	hash_init(cmd, hash);
	hash->registers[REG_A].x64 = 0x6a09e667;
	hash->registers[REG_B].x64 = 0xbb67ae85;
	hash->registers[REG_C].x64 = 0x3c6ef372;
	hash->registers[REG_D].x64 = 0xa54ff53a;
	hash->registers[REG_E].x64 = 0x510e527f;
	hash->registers[REG_F].x64 = 0x9b05688c;
	hash->registers[REG_G].x64 = 0x1f83d9ab;
	hash->registers[REG_H].x64 = 0x5be0cd19;
}

int				ft_sha512_update(t_hash_use *h_use)
{
	(void)h_use;
	return (1);
}

void			ft_sha512_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done)
{
	if (h_done)
		ft_ssl_print_hash(h_cmd, h_use, flag, 8);
	hash_destroy(h_use);
}
