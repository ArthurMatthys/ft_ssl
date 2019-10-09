/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sha256_fct.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:53:39 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 15:15:35 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/ft_ssl_hash.h"

unsigned 	s0_32(unsigned *words, int index)
{
	return (rightrot_32(words[index - 15], 7) ^ 
			rightrot_32(words[index - 15], 18) ^ 
			rightshift_32(words[index - 15], 3));
}

unsigned 	s1_32(unsigned *words, int index)
{
	return (rightrot_32(words[index - 2], 17) ^ 
			rightrot_32(words[index - 2], 19) ^ 
			rightshift_32(words[index - 2], 10));
}

unsigned 	S0_32(unsigned reg)
{
	return (rightrot_32(reg, 6) ^ 
			rightrot_32(reg, 11) ^ 
			rightrot_32(reg, 25));
}

unsigned 	S1_32(unsigned reg)
{
	return (rightrot_32(reg, 2) ^ 
			rightrot_32(reg, 13) ^ 
			rightrot_32(reg, 22));
}

