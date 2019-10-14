/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_md5_fct.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 10:08:48 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 09:39:19 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_hash.h"

uint32_t	f0(t_alltypes *registers)
{
	return ((registers[1].x32 & registers[2].x32) |
			((~registers[1].x32) & registers[3].x32));
}

uint32_t	f1(t_alltypes *registers)
{
	return ((registers[3].x32 & registers[1].x32) |
			((~registers[3].x32) & registers[2].x32));
}

uint32_t	f2(t_alltypes *registers)
{
	return (registers[1].x32 ^ registers[2].x32 ^ registers[3].x32);
}

uint32_t	f3(t_alltypes *registers)
{
	return (registers[2].x32 ^ (registers[1].x32 | (~registers[3].x32)));
}
