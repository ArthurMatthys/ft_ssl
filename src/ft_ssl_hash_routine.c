/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_hash_routine.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/02 16:08:41 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 11:01:35 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl_hash.h"

static void	add_len(t_hash_use *h_use, t_hash_cmd h_cmd)
{
	int		i;

	i = 0;
	if (h_cmd.size_len == 16)
	{
		h_use->len_msg.x64 *= 8;
		((char *)(h_use->block))[h_cmd.len_block - 16] = h_use->len_msg.x128;
	}
	else if (h_cmd.size_len == 8)
	{
		h_use->len_msg.x64 *= 8;
		while (i < 8)
		{
			((char *)(h_use->block))[h_cmd.len_block - 8 + i] = h_use->len_msg.c[i];
			i++;
		}

	}
}

static int	du_hash(t_hash_use *h_use, t_hash_cmd h_cmd)
{
	int		index;
	int		end;
	size_t	size;

	index = 0;
	end = 0;
	h_use->len_msg.x64 = ft_strlen(h_use->arg);
	size = h_use->len_msg.x64;
	while (h_use->len_msg.x64 - index >= (h_cmd.len_block - h_cmd.size_len))
	{
		h_use->block = ft_memmove(h_use->block, h_use->arg + index,
				min(h_cmd.len_block, h_use->len_msg.x64 - index));
		index += min(h_cmd.len_block, h_use->len_msg.x64 - index);
		if (size < h_cmd.len_block && (end = 1))
			h_use->block->c[size] = 0x80;
		size = h_use->len_msg.x64 - index;
		h_cmd.update(h_use);
		ft_bzero(h_use->block, h_cmd.len_block);
	}
	h_use->block = ft_memmove(h_use->block, h_use->arg + index,
			h_use->len_msg.x64 - index);
	if (!end)
		((char *)h_use->block)[h_use->len_msg.x32 % h_cmd.len_block] = 0x80;
	add_len(h_use, h_cmd);
	h_cmd.update(h_use);
	return (1);
}

static int	hash_input(char *str, t_hash_use *h_use, t_hash_cmd h_cmd, int flag)
{
	int		fd;
	int		padding_done;
	unsigned	index;
	size_t	size;

	padding_done = 0;
	index = 0;
	fd = str ? open_arg(str) : 0;
	size = 0;
	if (fd < 0)
		return (error_open(str, h_cmd.cmd, fd));
	while ((size = read(fd, ((char *)h_use->block) + index, h_cmd.len_block - index)) > 0)
	{
		index += size;
		if (flag & H_P)
			write(1, ((char *)h_use->block) + index - size, size);
		h_use->len_msg.x64 += size;
		if (index == h_cmd.len_block)
		{
			h_cmd.update(h_use);
			ft_bzero(h_use->block, h_cmd.len_block);
			index = 0;
		}
	}
	h_use->block->c[index++] = 0x80;
	if (index > h_cmd.len_block - h_cmd.size_len)
	{
		h_cmd.update(h_use);
		ft_bzero(h_use->block, h_cmd.len_block);
	}
	add_len(h_use, h_cmd);
	h_cmd.update(h_use);
	return (1);
}

void		ft_ssl_hash_routine(t_hash_cmd h_cmd, int flag, int cas, char *arg)
{
	t_hash_use	h_use;
	int			h_done;

	h_cmd.init(h_cmd, &h_use);
	h_use.arg = arg;
	if (cas == C_STRING)
		h_done = du_hash(&h_use, h_cmd);
	else
		h_done = hash_input(cas == C_FILE ? arg : NULL, &h_use, h_cmd, flag);
	h_cmd.close(&h_use, flag, h_done);
}
