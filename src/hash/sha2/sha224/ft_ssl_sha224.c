/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_sha224.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 15:51:01 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 09:39:37 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_hash.h"

void			ft_sha224_init(t_hash_cmd cmd, t_hash_use *hash)
{
	hash_init(cmd, hash);
	hash->registers[REG_A].x32 = 0xc1059ed8;
	hash->registers[REG_B].x32 = 0x367cd507;
	hash->registers[REG_C].x32 = 0x3070dd17;
	hash->registers[REG_D].x32 = 0xf70e5939;
	hash->registers[REG_E].x32 = 0xffc00b31;
	hash->registers[REG_F].x32 = 0x68581511;
	hash->registers[REG_G].x32 = 0x64f98fa7;
	hash->registers[REG_H].x32 = 0xbefa4fa4;
}

void			ft_sha224_close(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, int h_done)
{
	if (h_done)
		ft_ssl_print_hash(h_cmd, h_use, flag, 28);
	hash_destroy(h_use);
}
