/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 15:57:56 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 15:11:33 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "get_next_line.h"

static void	stdin_to_cmd()
{
	char	*buff;
	char	**new_argv;
	char	*tmp;
	int		i;

	
	ft_printf("ft_ssl>");
	while (get_next_line(0, &buff) > 0)
	{
		i = -1;
		tmp = ft_strjoin("./ft_ssl ", buff);
		new_argv = ft_strsplit(tmp, ' ');
		free(tmp);
		free(buff);
		get_command(i, new_argv, new_argv[1]);
		ft_freetab(new_argv);
		ft_printf("ft_ssl>");
	}
	free_fd();
	free(buff);
}


int		main(int argc, char **argv)
{
	if (argc < 2)
		stdin_to_cmd();
	else
		get_command(argc, argv, argv[1]);
	return (EXIT_SUCCES);
}
