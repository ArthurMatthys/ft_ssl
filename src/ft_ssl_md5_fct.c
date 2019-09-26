/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_md5_fct.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/18 09:02:25 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/18 16:09:11 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

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
