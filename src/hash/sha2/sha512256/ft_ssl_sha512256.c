/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_sha512256.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 12:35:50 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 13:00:42 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../../includes/ft_ssl_hash.h"

void			ft_sha512256_init(t_hash_cmd cmd, t_hash_use *hash)
{
	hash_init(cmd, hash);
	hash->registers[REG_A].x64 = 0x22312194FC2BF72C;
	hash->registers[REG_B].x64 = 0x9F555FA3C84C64C2;
	hash->registers[REG_C].x64 = 0x2393B86B6F53B151;
	hash->registers[REG_D].x64 = 0x963877195940EABD;
	hash->registers[REG_E].x64 = 0x96283EE2A88EFFE3;
	hash->registers[REG_F].x64 = 0xBE5E1E2553863992;
	hash->registers[REG_G].x64 = 0x2B0199FC2C85B8AA;
	hash->registers[REG_H].x64 = 0x0EB72DDC81C52CA2;
}

void			ft_sha512256_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done)
{
	if (h_done)
		ft_ssl_print_hash(h_cmd, h_use, flag, 32);
	hash_destroy(h_use);
}
