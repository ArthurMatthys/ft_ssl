/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_utils_reg.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 15:34:52 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/10 14:30:02 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_hash.h"

void	ft_ssl_load_registers(t_alltypes *dst, t_alltypes *src, unsigned nbr)
{
	unsigned 	index;

	index = 0;
	while (index < nbr)
	{
		dst[index].x128 = src[index].x128;
		index++;
	}
}

void	ft_ssl_add_registers(t_alltypes *dst, t_alltypes *src, unsigned nbr)
{
	unsigned 	index;

	index = 0;
	while (index < nbr)
	{
		dst[index].x128 += src[index].x128;
		index++;
	}
}
