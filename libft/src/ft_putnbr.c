/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 13:31:34 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 09:15:08 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long c)
{
	if (c >= 10)
	{
		ft_putnbr(c / 10);
		ft_putchar('0' + c % 10);
	}
	else if (0 <= c && c < 10)
		ft_putchar('0' + c);
	else
	{
		ft_putchar('-');
		if (c <= -10)
			ft_putnbr(-(c / 10));
		ft_putchar('0' - c % 10);
	}
}
