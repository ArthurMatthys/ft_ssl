/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_print_hash.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:33:12 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 12:48:41 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_hash.h"

static void		ft_ssl_print_sum(unsigned nb_bytes, t_hash_use *h_use,
		t_hash_cmd h_cmd)
{
	unsigned	i;
	unsigned	j;
	unsigned 	tot;
	t_alltypes	sum;

	i = 0;
	tot = 0;
	while (i < h_cmd.nb_register && tot < nb_bytes)
	{
		j = 0;
		sum = h_use->registers[i];
		while (j < h_cmd.size_register && tot < nb_bytes)
		{
			ft_printf("%.2x", h_cmd.endian ?
					sum.c[h_cmd.size_register - 1 - j] : sum.c[j]);
			j++;
			tot++;
		}
		i++;
	}
}

void			ft_ssl_print_hash(t_hash_cmd h_cmd, t_hash_use *h_use,
		int flag, unsigned nb_bytes)
{
	if (flag & H_P || flag & H_Q || !h_use->arg)
		ft_ssl_print_sum(nb_bytes, h_use, h_cmd);
	else if (flag & H_R)
	{
		ft_ssl_print_sum(nb_bytes, h_use, h_cmd);
		ft_printf(flag & H_S ? " \"%s\"" : " %s", h_use->arg);
	}
	else
	{
		ft_printf(flag & H_S ? "%s (\"%s\") = " : "%s (%s) = ",
				h_cmd.to_print, h_use->arg);
		ft_ssl_print_sum(nb_bytes, h_use, h_cmd);
	}
	ft_printf("\n");
}
