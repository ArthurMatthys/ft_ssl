/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/11 14:42:00 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/24 11:19:55 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_clearargs(t_arg *arguments)
{
	t_arg	*to_del;

	while (arguments)
	{
		to_del = arguments;
		if (to_del->cmd)
		{
			if (to_del->cmd->flag & 1 << 5)
				free(to_del->msg);
			else
				free(to_del->cmd);
		}
		arguments = arguments->next;
		free(to_del);
		to_del = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_arg	*arguments;
	t_arg	*tmp;
	int		i;

	arguments = NULL;
	if (argc < 2)
		return (!ssl_usage());
	i = ssl_handle_input(&arguments, argc, argv);
	if (i >= 1)
	{
		ft_clearargs(arguments);
		if (i == 2)
			ft_printf("-s requires one argument\n");
		return (1);
	}
//	arguments->cmd->handler(&arguments);
//	ft_clearargs(arguments);
//	print_struct(&arguments);
	while (arguments)
	{
		tmp = arguments;
		if (tmp->cmd)
		{
			if (!(tmp->cmd->flag & T_BADINPUT))
				tmp->cmd->handler(tmp);
			if (tmp->cmd->flag & T_TODEL)
				free(tmp->msg);
			free(tmp->cmd);
		}
		arguments = arguments->next;
		free(tmp);
		tmp = NULL;
	}
	return (0);
}
