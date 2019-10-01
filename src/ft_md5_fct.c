/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_md5_fct.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 10:08:48 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/01 10:09:10 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_hash.h"

unsigned	f0(unsigned *abcd)
{
	return ((abcd[1] & abcd[2]) | ((~abcd[1]) & abcd[3]));
}

unsigned	f1(unsigned *abcd)
{
	return ((abcd[3] & abcd[1]) | ((~abcd[3]) & abcd[2]));
}

unsigned	f2(unsigned *abcd)
{
	return (abcd[1] ^ abcd[2] ^ abcd[3]);
}

unsigned	f3(unsigned *abcd)
{
	return (abcd[2] ^ (abcd[1] | (~abcd[3])));
}

