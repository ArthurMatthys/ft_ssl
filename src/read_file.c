/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_file.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/03 11:30:17 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/03 18:12:21 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int		open_arg(char *str)
{
	struct stat	buf;
	int			fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	if (fstat(fd, &(buf)) < 0)
		return (-2);
	if (buf.st_mode == 16877)
		return (-3);
	return (fd);
}

int		read_fd(t_alltypes *buff, int fd, int to_read)
{
	int	size;

	ft_bzero(buff, to_read);
	size = read(fd, buff, to_read);
	return (size);
}
