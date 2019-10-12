/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_sha512224.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 12:35:35 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 12:54:51 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../../includes/ft_ssl_hash.h"

void			ft_sha512224_init(t_hash_cmd cmd, t_hash_use *hash)
{
	hash_init(cmd, hash);
	hash->registers[REG_A].x64 = 0x8C3D37C819544DA2;
	hash->registers[REG_B].x64 = 0x73E1996689DCD4D6;
	hash->registers[REG_C].x64 = 0x1DFAB7AE32FF9C82;
	hash->registers[REG_D].x64 = 0x679DD514582F9FCF;
	hash->registers[REG_E].x64 = 0x0F6D2B697BD44DA8;
	hash->registers[REG_F].x64 = 0x77E36F7304C48942;
	hash->registers[REG_G].x64 = 0x3F9D85A86A1D36C8;
	hash->registers[REG_H].x64 = 0x1112E6AD91D692A1;
}

void			ft_sha512224_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done)
{
	if (h_done)
		ft_ssl_print_hash(h_cmd, h_use, flag, 28);
	hash_destroy(h_use);
}
