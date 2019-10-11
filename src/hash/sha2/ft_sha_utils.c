/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sha_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 15:17:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/11 15:59:12 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/ft_ssl_hash.h"

size_t	ch(size_t reg_e, size_t reg_f, size_t reg_g)
{
	return ((reg_e & reg_f) ^ (~reg_e & reg_g));
}

size_t	maj(size_t reg_a, size_t reg_b, size_t reg_c)
{
	return ((reg_a & reg_b) ^ (reg_a & reg_c) ^ (reg_b & reg_c));
}

void		rot_registers_sha(t_alltypes *reg, size_t *tmp)
{
	reg[REG_H].x64 = reg[REG_G].x64;
	reg[REG_G].x64 = reg[REG_F].x64;
	reg[REG_F].x64 = reg[REG_E].x64;
	reg[REG_E].x64 = reg[REG_D].x64 + tmp[0];
	reg[REG_D].x64 = reg[REG_C].x64;
	reg[REG_C].x64 = reg[REG_B].x64;
	reg[REG_B].x64 = reg[REG_A].x64;
	reg[REG_A].x64 = tmp[0] + tmp[1];
}
