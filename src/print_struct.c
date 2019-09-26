/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_struct.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/13 14:32:00 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/22 15:52:52 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

void	print_struct(t_arg **arguments)
{
	t_arg	*it;

	it = *arguments;
	while (it)
	{
		printf("Message to code : |%s|\n", it->msg);
		printf("Command : |%s|\n", it->cmd->name);
		printf("flag : |%i|\n", it->cmd->flag);
		it = it->next;
	}
}
