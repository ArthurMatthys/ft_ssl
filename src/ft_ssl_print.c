/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_print.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/23 08:43:52 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/23 10:55:05 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/ft_ssl_md5.h"

static void		ft_ssl_print_hexa(unsigned *sum, int size)
{
	int			i;
	int			j;
	t_digest	tmp;

	i = -1;
	while (++i < size)
	{
		tmp.i = sum[i];
		j = -1;
		while (++j < 4)
			ft_printf("%.2x", tmp.c[j]);
	}
}

void		ft_ssl_md5_print(t_arg *argument, unsigned *sum, char *filename)
{
/*	char	*add;

	if (!filename)
		add[0] = '\"';
	else
		add = "";
*///	ft_printf("flags : %d\n", argument->cmd->flag);
	if (argument->cmd->flag & T_P)
		ft_printf("%s", argument->msg);
	if (!(argument->cmd->flag & (T_Q | T_P)))
	{
		if (!(argument->cmd->flag & T_R) && (filename))
			ft_printf("%s (%s) = ", argument->cmd->to_print, filename);
		else if (!(argument->cmd->flag & T_R))
			ft_printf("%s (\"%s\") = ", argument->cmd->to_print, argument->msg);
	}
	ft_ssl_print_hexa(sum, argument->cmd->nb_unsigned);
	if (!(argument->cmd->flag & (T_Q | T_P)))
	{
		if ((argument->cmd->flag & T_R) && (filename))
			ft_printf(" %s", filename);
		else if ((argument->cmd->flag & T_R))
			ft_printf(" \"%s\"", argument->msg);
	}
	ft_printf("\n");
}
