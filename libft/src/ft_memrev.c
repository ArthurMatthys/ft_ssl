/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:30:02 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 14:30:22 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_memrev(t_alltypes *len, int size)
{
	int				i;
	char			tmp;

	i = -1;
	while (++i < --size)
	{
		tmp = len->c[size];
		len->c[size] = len->c[i];
		len->c[i] = tmp;
	}
}
