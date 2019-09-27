/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_setup.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/12 18:25:23 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/24 11:34:59 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_cmd	*check_cmd(t_cmd *cmd, char *str)
{
	int i;

	i = 0;
	while (i < NB_CMD)
	{
		if (ft_strequ(g_cmd[i].name, str))
		{
			cmd = &g_cmd[i];
			return (cmd);
		}
		else
			i++;
	}
	return (NULL);
}

static t_arg	*create_arg(t_arg *argument, t_cmd *cmd)
{
	t_arg *new_arg;
	t_cmd *cpy;

	if (!(new_arg = (t_arg *)ft_memalloc(sizeof(t_arg))))
		return (NULL);
	if (!(cpy = (t_cmd *)ft_memalloc(sizeof(t_cmd))))
		return (NULL);
	if (!argument)
	{
		*cpy = *cmd;
		new_arg->cmd = cpy;
		new_arg->previous = argument;
//		printf("flags1 : %d\tflags2 : %d\n", cmd->flag, new_arg->cmd->flag);
	}
	else
	{
		*cpy = *argument->cmd;
		new_arg->cmd = cpy;
		if (new_arg->cmd->index < 2)
			new_arg->cmd->flag = (argument->cmd->flag) & (T_R | T_Q);
		if ((argument->cmd->flag & T_P) || (argument->cmd->flag & T_PDONE))
			cpy->flag |= T_PDONE;
		new_arg->previous = argument;
	}
	return (new_arg);
}

int			ssl_handle_input(t_arg **arguments, int argc, char **argv)
{
	int		i;
	int		j;
	t_cmd	*cmd;
	t_arg	*it;
	t_arg	*new_arg;

	cmd = NULL;
	it = NULL;
	i = 2;
	if (!(cmd = check_cmd(cmd, argv[1])))
		return (!ssl_list_command(argv[1]));
	if (argc == 2)
	{
		new_arg = create_arg(it, cmd);
		new_arg->cmd->flag |= T_P;
		*arguments = new_arg;
		return (0);
	}
	while (i < argc)
	{
		if (!(new_arg = create_arg(it, cmd)))
			return (1);
		j = new_arg->cmd->parser(new_arg, argv, &i, argc);
		if (j == 2)
			return (1);
		if (it)
		{
			it->next = new_arg;
			it = it->next;
		}
		else
		{
			*arguments = new_arg;
			it = new_arg;
		}
		if (!j)
		{
			it->cmd->flag = (it->cmd->flag & T_S) ? T_BADINPUT : 0;
			return (2);
		}
	}
	return (0);
}
