/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 09:43:00 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 10:31:37 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	new = ft_memalloc_wrapper(size);
	if (ptr)
	{
		new = ft_memmove(new, ptr, size);
		free(ptr);
	}
	ptr = new;
	return (ptr);
}
