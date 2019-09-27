/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_getstdin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/20 09:05:40 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/24 17:02:02 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

static int	ft_addloc(char **msg, char *line, size_t len_line)
{
	char	*tmp;
	size_t	len_msg;
	size_t	new_len;

	tmp = NULL;
	if (!(*msg))
		len_msg = 0;
	else
		len_msg = ft_strlen(*msg);
	new_len = len_msg + len_line + 1;
	if (!(tmp = (char *)ft_memalloc(sizeof(char) * new_len)))
		return (0);
	tmp = ft_memcpy(tmp, *msg, len_msg);
	tmp = ft_strncat(tmp, line, new_len);
	tmp[new_len - 1] = '\0';
	free(*msg);
	*msg = tmp;
	return (1);
}


t_arg	*get_stdin(t_cmd *cmd)
{
	t_arg	*new_arg;
	int	size;
	char	*msg;
	char	line[READ_SIZE];
	t_cmd	*cpy;

	
	msg = NULL;
	if (!(new_arg = (t_arg *)ft_memalloc(sizeof(t_arg))))
		return (NULL);
	if (!(cpy = (t_cmd *)ft_memalloc(sizeof(t_cmd))))
		return (NULL);
	*cpy = *cmd;
	new_arg->cmd = cpy;
	while ((size = read(0, line, READ_SIZE)) > 0)
	{
		ft_addloc(&msg, line, size);
	}
	if (!msg)
		new_arg->msg = "";
	else
		new_arg->msg = msg;
	new_arg->cmd->flag |= 1 << 5;
	return (new_arg);
}

static int		open_file(t_arg *argument)
{
	struct	stat buf;
	int		fd;

	fd = open(argument->msg, O_RDONLY);
	if (argument->cmd->flag & T_P)
		return (0);
	if (fd < 0)
		return (-1);
	if (fstat(fd, &(buf)) < 0)
	{
		ft_printf("ERROR : Failed to get filedescriptor stats.\n");
		return (-1);
	}
	if (buf.st_mode == 16877)
		return (-1);
	return (fd);
}

int		read_file(t_arg *argument, size_t *size_tot)
{
	int		fd;
	int		size;
	char	*msg;
	char	line[READ_SIZE + 1];

	msg = NULL;
	if ((argument->cmd->flag & T_P) && (argument->cmd->flag & T_PDONE))
	{
		argument->msg = "";
		return (1);
	}
	fd = open_file(argument);
	if (fd < 0)
		return (0);
	while ((size = read(fd, line, READ_SIZE)) > 0)
	{
		line[size] = 0;
		ft_addloc(&msg, line, size);
		*size_tot += size;
	}
	free_fd();
	if (!msg)
		argument->msg = "";
	else
		argument->msg = msg;
	argument->cmd->flag |= 1 << 5;
	return (1);
}
