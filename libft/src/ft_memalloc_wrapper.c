/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc_wrapper.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/01 14:47:09 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 09:15:39 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc_wrapper(size_t size)
{
	void	*ptr;

	ptr = ft_memalloc(size);
	if (!ptr)
	{
		write(2, "Failed to malloc\n", 17);
		exit(EXIT_FAILLURE);
	}
	else
		return (ptr);
}
