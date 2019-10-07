/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_struct.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/03 18:30:43 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 11:40:07 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl_hash.h"

void	print_block(t_hash_cmd h_cmd, t_hash_use *h_use)
{
	unsigned	i;

	i = 0;
//	ft_printf("%d\n", h_cmd.len_block);
	while (i < h_cmd.len_block)
	{
		ft_printf("%.2x", h_use->block->c[i]);
		i++;
	}
	ft_printf("\n");
}
