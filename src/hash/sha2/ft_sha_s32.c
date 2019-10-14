/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sha_s32.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:53:39 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 09:40:18 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_hash.h"

unsigned	smas0(unsigned word)
{
	return (rightrot_32(word, 7) ^
			rightrot_32(word, 18) ^
			rightshift_32(word, 3));
}

unsigned	smas1(unsigned word)
{
	return (rightrot_32(word, 17) ^
			rightrot_32(word, 19) ^
			rightshift_32(word, 10));
}

unsigned	bigs0(unsigned reg)
{
	return (rightrot_32(reg, 2) ^
			rightrot_32(reg, 13) ^
			rightrot_32(reg, 22));
}

unsigned	bigs1(unsigned reg)
{
	return (rightrot_32(reg, 6) ^
			rightrot_32(reg, 11) ^
			rightrot_32(reg, 25));
}
