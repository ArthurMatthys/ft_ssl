/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_getstdin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/20 09:05:40 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/23 17:43:53 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

static int	ft_addloc(char **msg, char *line)
{
	char	*tmp;
	size_t	len_msg;
	size_t	len_line;
	size_t	new_len;

	if (!(*msg))
		len_msg = 0;
	else
		len_msg = ft_strlen(*msg);
	len_line = ft_strlen(line);
	new_len = len_msg + len_line + 1;
	if (!(tmp = (char *)ft_memalloc(sizeof(char) * new_len)))
		return (0);
	tmp = ft_memcpy(tmp, *msg, len_msg);
	tmp = ft_strncat(tmp, line, new_len);
	tmp[new_len - 1] = '\n';
	free(*msg);
	*msg = tmp;
	return (1);
}


t_arg	*get_stdin(t_cmd *cmd)
{
	t_arg	*new_arg;
	char	*msg;
	char	*line;
	t_cmd	*cpy;

	
	msg = NULL;
	if (!(new_arg = (t_arg *)ft_memalloc(sizeof(t_arg))))
		return (NULL);
	if (!(cpy = (t_cmd *)ft_memalloc(sizeof(t_cmd))))
		return (NULL);
	*cpy = *cmd;
	new_arg->cmd = cpy;
	while (get_next_line(0, &line))
	{
		ft_addloc(&msg, line);
		free(line);
	}
	free(line);
	if (!msg)
		new_arg->msg = "";
	else
		new_arg->msg = msg;
	new_arg->cmd->flag |= 1 << 5;
	return (new_arg);
}

static int		open_file(t_arg *argument)
{
	struct stat buf;
	if (argument->cmd->flag & T_P)
		return (0);
	return (1);
}

int		read_file(t_arg *argument)
{
	int		fd;
	char	*msg;
	char	*line;

	msg = NULL;
	if ((argument->cmd->flag & T_P) && (argument->cmd->flag & T_PDONE))
	{
		argument->msg = "";
		return (1);
	}
	fd = argument->cmd->flag & T_P ? 0 : open(argument->msg, O_RDONLY);
	ft_printf("filename : %s\tfd -> %d\n", argument->msg, fd);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line))
	{
		ft_addloc(&msg, line);
		free(line);
	}
	free_fd();
	free(line);
	if (!msg)
		argument->msg = "";
	else
		argument->msg = msg;
	argument->cmd->flag |= 1 << 5;
	return (1);
}
