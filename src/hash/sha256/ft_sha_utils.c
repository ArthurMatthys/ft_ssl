/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sha_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 15:17:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 17:10:30 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/ft_ssl_hash.h"

unsigned	ch_32(unsigned reg_e, unsigned reg_f, unsigned reg_g)
{
	return ((reg_e & reg_f) ^ (~reg_e & reg_g));
}

unsigned	maj_32(unsigned reg_a, unsigned reg_b, unsigned reg_c)
{
	return ((reg_a & reg_b) ^ (reg_a & reg_c) ^ (reg_b & reg_c));
}

void		rot_registers_32(unsigned *reg, unsigned tmp1, unsigned tmp2)
{
	reg[REG_H] = reg[REG_G];
	reg[REG_G] = reg[REG_F];
	reg[REG_F] = reg[REG_E];
	reg[REG_E] = reg[REG_D] + tmp1;
	reg[REG_D] = reg[REG_C];
	reg[REG_C] = reg[REG_B];
	reg[REG_B] = reg[REG_A];
	reg[REG_A] = tmp1 + tmp2; 
}