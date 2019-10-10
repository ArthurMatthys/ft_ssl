/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_hash_utils.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/02 08:15:20 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 10:00:21 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_hash.h"


unsigned		leftrot_32(unsigned word, short rot)
{
	return ((word << rot) | (word >> (32 - rot)));
}

unsigned		rightrot_32(unsigned word, short rot)
{
	return ((rightshift_32(word, rot)) | (word << (32 - rot)));
}

unsigned		rightshift_32(unsigned word, short shift)
{
	return ((word & 0xFFFFFFFF) >> shift);
}

