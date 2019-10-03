/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_hash_utils.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/02 08:15:20 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/03 16:48:29 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl_hash.h"

static void		ft_ssl_print_sum(t_hash_cmd h_cmd, t_hash_use *h_use)
{
	unsigned	i;
	unsigned	j;
	t_alltypes	sum;

	i = 0;
	ft_printf("yoooo\n");
	while (i < h_cmd.nb_register)
	{
		j = 0;
		sum = h_use->registers[i];
		while (j < h_cmd.size_register)
		{
			ft_printf("%.2x", sum.c[j]);
			j++;
		}
		i++;
	}
}


void		ft_ssl_print_hash(t_hash_cmd h_cmd, t_hash_use *h_use, int flag)
{
	if (flag & H_P || flag & H_Q)
		ft_ssl_print_sum(h_cmd, h_use);


}

unsigned	rot_32(unsigned  word, short rot)
{
	return ((word << rot) | (word >> (32 - rot)));
}
