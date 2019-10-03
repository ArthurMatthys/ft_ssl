/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ssl_hash_routine.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/02 16:08:41 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/02 16:48:21 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl_hash.h"

void	ft_ssl_hash_routine(t_hash_cmd h_cmd, int flag, int cas, char *arg)
{
	t_hash_use	h_use;
	
	h_cmd.init(h_cmd, &h_use);
	h_use.arg = arg;
	if (cas & C_STRING)
		du_hash(flag, h_use, h_cmd);
	else
		hash_input(C_FILE ? arg : NULL, flag, h_use, h_cmd);
	h_cmd.close(&h_use);
}
