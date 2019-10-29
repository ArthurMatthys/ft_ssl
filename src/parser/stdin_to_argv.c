/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stdin_to_argv.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/19 12:00:47 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 15:56:06 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_ssl_stdin.h"

static int		next_spec_char(char *input)
{
	char	spec[5];
	int		index[4];
	int		i;
	int		m;

	ft_strcpy(spec, "\'\"` ");
	i = -1;
	while (++i < 4)
		index[i] = ft_strindex(input, spec[i]);
	m = ft_strlen(input);
	i = -1;
	while (++i < 4)
		if (index[i] < m && index[i] != -1)
			m = index[i];
	return ((size_t)m == ft_strlen(input) ? -1 : m);
}

static int		get_next_word(char *input)
{
	int		i;

	i = 0;
	while (input[i] && input[i] == ' ')
		i++;
	return (i);
}

static char		*get_arg(char *input, int *n)
{
	char	*chr;
	char	*new_arg;
	int		new_len;

	chr = NULL;
	new_len = 0;
	if (input[*n] == ' ')
	{
		new_arg = ft_strndup(input, *n);
		*n += get_next_word(input + *n);
	}
	else
	{
		chr = ft_strchr(input + 1, input[*n]);
		new_len = ft_strlen(chr);
		new_arg = ft_strndup(input + 1, ft_strlen(input) - new_len - 1);
		*n += ft_strlen(new_arg) + 2 + get_next_word(chr + 1);
	}
	return (new_arg);
}

static char		**split_to_argv(char **input, int nbr_arg)
{
	char	**res;
	char	*cpy;
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	cpy = *input;
	res = (char **)ft_memalloc_wrapper(sizeof(char *) * (nbr_arg + 1));
	while (i < (int)ft_strlen(cpy))
	{
		ft_printf("|%s|\n", cpy + i);
		n = next_spec_char(cpy + i);
		if (n == -1)
		{
			res[j] = ft_strdup(cpy + i);
			n = ft_strlen(res[j]);
		}
		else
			res[j] = get_arg(cpy + i, &n);
		j++;
		i += n;
	}
	return (res);
}

char			**stdin_to_argv(char **input)
{
	int		nbr_arg;
	char	**res;

	nbr_arg = clean_stdin(input);
	ft_printf("nbr_arg : %d\n", nbr_arg);
	ft_printf("input : |%s|\n", *input);
	res = split_to_argv(input, nbr_arg);
	return (res);
}
