/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sha_s64.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 11:57:24 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 09:40:35 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_hash.h"

size_t	smas0l(size_t word)
{
	return (rightrotl(word, 1) ^
			rightrotl(word, 8) ^
			rightshiftl(word, 7));
}

size_t	smas1l(size_t word)
{
	return (rightrotl(word, 19) ^
			rightrotl(word, 61) ^
			rightshiftl(word, 6));
}

size_t	bigs0l(size_t reg)
{
	return (rightrotl(reg, 28) ^
			rightrotl(reg, 34) ^
			rightrotl(reg, 39));
}

size_t	bigs1l(size_t reg)
{
	return (rightrotl(reg, 14) ^
			rightrotl(reg, 18) ^
			rightrotl(reg, 41));
}
