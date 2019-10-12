/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_sha384.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 12:17:34 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 12:49:02 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../../includes/ft_ssl_hash.h"

void			ft_sha384_init(t_hash_cmd cmd, t_hash_use *hash)
{
	hash_init(cmd, hash);
	hash->registers[REG_A].x64 = 0xcbbb9d5dc1059ed8;
	hash->registers[REG_B].x64 = 0x629a292a367cd507;
	hash->registers[REG_C].x64 = 0x9159015a3070dd17;
	hash->registers[REG_D].x64 = 0x152fecd8f70e5939;
	hash->registers[REG_E].x64 = 0x67332667ffc00b31;
	hash->registers[REG_F].x64 = 0x8eb44a8768581511;
	hash->registers[REG_G].x64 = 0xdb0c2e0d64f98fa7;
	hash->registers[REG_H].x64 = 0x47b5481dbefa4fa4;
}

void			ft_sha384_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done)
{
	if (h_done)
		ft_ssl_print_hash(h_cmd, h_use, flag, 48);
	hash_destroy(h_use);
}
