/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_hash_utils.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/02 08:15:20 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 17:07:16 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_hash.h"

static void		ft_ssl_print_sum(t_hash_cmd h_cmd, t_hash_use *h_use)
{
	unsigned	i;
	unsigned	j;
	t_alltypes	sum;

	i = 0;
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

void			ft_ssl_print_hash(t_hash_cmd h_cmd, t_hash_use *h_use, int flag)
{
	if (flag & H_P || flag & H_Q || !h_use->arg)
		ft_ssl_print_sum(h_cmd, h_use);
	else if (flag & H_R)
	{
		ft_ssl_print_sum(h_cmd, h_use);
		ft_printf(flag & H_S ? " \"%s\"" : " %s", h_use->arg);
	}
	else
	{
		ft_printf(flag & H_S ? "%s (\"%s\") = " : "%s (%s) = ",
				h_cmd.to_print, h_use->arg);
		ft_ssl_print_sum(h_cmd, h_use);
	}
	ft_printf("\n");
}

unsigned		leftrot_32(unsigned word, short rot)
{
	return ((word << rot) | (word >> (32 - rot)));
}

unsigned		rightrot_32(unsigned word, short rot)
{
	return ((word >> rot) | (word << (32 - rot)));
}

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
