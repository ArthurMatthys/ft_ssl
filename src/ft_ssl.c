/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 15:57:56 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 11:29:51 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

int			main(int argc, char **argv)
{
	if (argc < 2)
		stdin_to_cmd();
	else
		get_command(argc, argv, argv[1]);
	return (EXIT_SUCCES);
}
