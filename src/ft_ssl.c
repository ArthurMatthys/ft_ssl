/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 15:57:56 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 13:15:36 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (ssl_usage());
	get_command(argc, argv);
	return (EXIT_SUCCES);
}
