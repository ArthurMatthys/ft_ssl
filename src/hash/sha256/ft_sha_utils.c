/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sha_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 15:17:42 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 15:29:47 by amatthys    ###    #+. /#+    ###.fr     */
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
