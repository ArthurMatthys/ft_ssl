/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_md5_parser.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/15 13:40:26 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/24 17:02:01 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

static int	find_flag(t_arg *new_arg, char *arg)
{
	int j;

	j = 0;
	while (j < new_arg->cmd->nb_flag)
	{
		if (ft_strequ(arg, new_arg->cmd->flags[j]))
			return (j);
		j++;
	}
	return (j);
}

static int	handle_first_arg(t_arg *new_arg, char *arg)
{
	int		j;

	j = find_flag(new_arg, arg);
	if (j == new_arg->cmd->nb_flag)
	{
		new_arg->msg = arg;
		return (j);
	}
	new_arg->cmd->flag |= 1 << j;
	return (j);
}

static int	handle_following_arg(t_arg *new_arg, char *arg)
{
	int		j;

	j = find_flag(new_arg, arg);
	if (!(new_arg->previous->cmd->flag & T_S) && !(new_arg->previous->cmd->flag & T_P))
		j = new_arg->cmd->nb_flag;
	return (j);
}

int			ft_ssl_md5_parser(t_arg *new_arg, char **argv, int *i, int argc)
{
	int		j;

	while (*i < argc)
	{
		j = 0;
		if (!new_arg->previous)
			j = handle_first_arg(new_arg, argv[*i]);
		else
			j = handle_following_arg(new_arg, argv[*i]);
		new_arg->cmd->flag |= 1 << j;
		if (j == new_arg->cmd->nb_flag)
			new_arg->msg = argv[*i];
		else if (j == 3)
			new_arg->msg = "";
		else if (!j)
		{
			if (*i == argc - 1)
				return (0);
			(*i)++;
			new_arg->msg = argv[*i];
		}
		if (new_arg->msg && (*i)++)
			return (1);
		(*i)++;
	}
	return (2);
}
