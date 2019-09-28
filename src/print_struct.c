/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_struct.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/13 14:32:00 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/24 09:29:12 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	print_struct(t_arg **arguments)
{
	t_arg	*it;

	it = *arguments;
	while (it)
	{
		ft_printf("Message to code : |%s|\n", it->msg);
		ft_printf("Command : |%s|\n", it->cmd->name);
		ft_printf("flag : |%i|\n", it->cmd->flag);
		it = it->next;
	}
}
