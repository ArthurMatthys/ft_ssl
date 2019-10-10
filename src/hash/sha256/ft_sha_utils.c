/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sha_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 15:17:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 14:30:57 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/ft_ssl_hash.h"

unsigned	ch(unsigned reg_e, unsigned reg_f, unsigned reg_g)
{
	return ((reg_e & reg_f) ^ (~reg_e & reg_g));
}

unsigned	maj(unsigned reg_a, unsigned reg_b, unsigned reg_c)
{
	return ((reg_a & reg_b) ^ (reg_a & reg_c) ^ (reg_b & reg_c));
}

void		rot_registers_sha(t_alltypes *reg, unsigned *tmp)
{
	reg[REG_H].x32 = reg[REG_G].x32;
	reg[REG_G].x32 = reg[REG_F].x32;
	reg[REG_F].x32 = reg[REG_E].x32;
	reg[REG_E].x32 = reg[REG_D].x32 + tmp[0];
	reg[REG_D].x32 = reg[REG_C].x32;
	reg[REG_C].x32 = reg[REG_B].x32;
	reg[REG_B].x32 = reg[REG_A].x32;
	reg[REG_A].x32 = tmp[0] + tmp[1]; 
}
