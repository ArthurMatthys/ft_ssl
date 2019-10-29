/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   argv_utils.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/19 11:33:13 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 15:43:07 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"

char		*remove_nl(char *input)
{
	char	*cpy;
	size_t	len;

	len = ft_strlen(input);
	cpy = input;
	if (input[len - 1] == '\n')
	{
		input = ft_strndup(input, len - 1);
		free(cpy);
	}
	return (input);
}

static int	update_nbr_block(unsigned *stat, size_t *nbr_char, int c)
{
	int		quote[3];

	quote[0] = C_SQUOTE;
	quote[1] = C_DQUOTE;
	quote[2] = C_BQUOTE;
	if (c < 3)
	{
		if (*stat & quote[c])
			*stat &= 0xFFFFFFF8;
		else if (!(*stat & 0x07))
			*stat |= quote[c];
		else
			return (1);
	}
	if (*nbr_char || c < 3)
		(*stat) += (1 << 3);
	*nbr_char = 0;
	return (1);
}

static int	check_parity(char *input)
{
	unsigned		stat;
	size_t			i;
	size_t			nbr_char;

	i = 0;
	stat = 0;
	nbr_char = 0;
	while (input[i])
	{
		if (input[i] > 32 && input[i] < 127 &&
				input[i] != '\'' && input[i] != '\"' && input[i] != '`')
			nbr_char++;
		else if (input[i] == ' ' && !(stat & 0x07))
			update_nbr_block(&stat, &nbr_char, 4);
		else if (input[i] == '\"' || input[i] == '\'' || input[i] == '`')
			update_nbr_block(&stat, &nbr_char, (input[i] % 11) % 3);
		i++;
	}
	update_nbr_block(&stat, &nbr_char, 4);
	return (stat);
}

static char	*remove_excess(char *input, int state)
{
	char	*excess;
	size_t	len_excess;

	if (state & C_SQUOTE)
		excess = ft_strrchr(input, '\'');
	else if (state & C_DQUOTE)
		excess = ft_strrchr(input, '\"');
	else
		excess = ft_strrchr(input, '`');
	len_excess = ft_strlen(excess);
	ft_printf("|%s| removed due to the lack of quote parity\n", excess);
	return (ft_strndup(input, ft_strlen(input) - len_excess));
}

int			clean_stdin(char **input)
{
	int		state;
	char	*cpy;

	state = check_parity(*input);
	if (state & 0x07)
	{
		cpy = *input;
		*input = remove_excess(*input, state);
		free(cpy);
		cpy = NULL;
	}
	return (state >> 3);
}
