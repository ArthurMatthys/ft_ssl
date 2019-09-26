/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ssl_md5.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/12 18:37:28 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/23 17:43:54 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl_md5.h"

static void		update_cursor(int *a, int *b)
{
	if (!*a % (SIZE_BLOCK / LEN_BYTES))
	{
		*a = 0;
		*b += 1;
	}
}

static int		padding_md5(t_arg *arguments, t_block	**block)
{
	size_t	tot_bits;
	int		nbr_block;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tot_bits = ft_strlen(arguments->msg) * LEN_BYTES;
	nbr_block = (tot_bits / SIZE_BLOCK) + ((tot_bits % SIZE_BLOCK) > 448 ? 2 : 1);
	if (!(*block = (t_block *)ft_memalloc(sizeof(t_block) * (nbr_block))))
		return (ssl_usage());
	while (arguments->msg[i + (j * SIZE_BLOCK / LEN_BYTES)])
	{
		(*block)[j].c[i] = arguments->msg[i + (j * SIZE_BLOCK / LEN_BYTES)];
		i++;
		update_cursor(&i, &j);
	}
	(*block)[j].c[i++] = 0x80;
	update_cursor(&i, &j);
	while (i % (448 / LEN_BYTES))
	{
		(*block)[j].c[i++] = 0;
		update_cursor(&i, &j);
	}
	((*block)[nbr_block - 1]).s[7] = tot_bits;
	return (nbr_block);
}

static unsigned	roll(unsigned f, short g)
{
	return ((f << g) | (f >> (32 - g)));
}

static void ft_process_md5_inner_loop(unsigned *abcd, t_block chunk)
{
	int		i;
	int		j;
	unsigned f;
	short	g;
	int		*rot;
	dgstfct	ff;

	i = -1;
	while (++i < 4)
	{
		ff = g_fct[i];
		rot = g_s[i];
		j = -1;
		while (++j < 16)
		{
			g = (g_add[i] + g_multiply[i] * j) % 16;
			f = abcd[1] + roll(abcd[0] + ff(abcd) + g_k[16 * i + j] + chunk.i[g], rot[j % 4]);
			abcd[0] = abcd[3];
			abcd[3] = abcd[2];
			abcd[2] = abcd[1];
			abcd[1] = f;
		}
	}
}

static void	ft_process_md5(t_block *chunk, unsigned *h, int nbr_block)
{
	int		i;
	unsigned	abcd[4];
	int		j;

	i = -1;
	h[0] = A0;
	h[1] = B0;
	h[2] = C0;
	h[3] = D0;
	while (++i < nbr_block)
	{
		abcd[0] = h[0];
		abcd[1] = h[1];
		abcd[2] = h[2];
		abcd[3] = h[3];
		ft_process_md5_inner_loop(abcd, chunk[i]);
		j = -1;
		while (++j < 4)
			h[j] += abcd[j];
	}
}


int			ft_ssl_md5(t_arg *argument)
{
	t_block		*block;
	unsigned		sum[4];
	int			nbr_block;
	char		*filename;

	if (!argument->msg && !(argument->cmd->flag & T_BADINPUT))
		return (1);
	if (argument->cmd->flag & T_BADINPUT)
	{
		ft_printf("\"-s\" requires an extra argument\n");
		return (!ssl_usage());
	}
	filename = (!(argument->cmd->flag & (T_S)) ? argument->msg : NULL);
	if ((filename || argument->cmd->flag & T_P) && !read_file(argument))
	{
		ft_printf("%s : Is a directory or hasn't been found\n", filename);
		return (1);
	}
	if (!(nbr_block = padding_md5(argument, &block)))
		return (0);
	ft_process_md5(block, &sum[0], nbr_block);
	free(block);
	block= NULL;
	ft_ssl_md5_print(argument, sum, filename);
	return (1);
}
