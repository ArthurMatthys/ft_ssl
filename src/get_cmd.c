/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_cmd.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <amatthys@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 16:05:59 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 09:38:24 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_hash.h"

const t_list_cmd g_list_cmd[NB_CMD] =
{
	{"md5", &ssl_hash, 0},
	{"sha224", &ssl_hash, 1},
	{"sha256", &ssl_hash, 2},
	{"sha384", &ssl_hash, 3},
	{"sha512", &ssl_hash, 4},
	{"sha512224", &ssl_hash, 5},
	{"sha512256", &ssl_hash, 6},
};

const t_hash_cmd	g_hash_cmd[NB_HASH_FUNCTION] =
{
	{"md5", "MD5", &ft_md5_init, &ft_md5_update,
		&ft_md5_close, {"-s", "-r", "-q", "-p"}, 64, 4, 4, 8, 0},
	{"sha224", "SHA224", &ft_sha224_init, &ft_sha256_update,
		&ft_sha224_close, {"-s", "-r", "-q", "-p"}, 64, 8, 4, 8, 1},
	{"sha256", "SHA256", &ft_sha256_init, &ft_sha256_update,
		&ft_sha256_close, {"-s", "-r", "-q", "-p"}, 64, 8, 4, 8, 1},
	{"sha384", "SHA384", &ft_sha384_init, &ft_sha512_update,
		&ft_sha384_close, {"-s", "-r", "-q", "-p"}, 128, 8, 8, 16, 1},
	{"sha512", "SHA512", &ft_sha512_init, &ft_sha512_update,
		&ft_sha512_close, {"-s", "-r", "-q", "-p"}, 128, 8, 8, 16, 1},
	{"sha512224", "SHA512224", &ft_sha512224_init, &ft_sha512_update,
		&ft_sha512224_close, {"-s", "-r", "-q", "-p"}, 128, 8, 8, 16, 1},
	{"sha512256", "SHA512256", &ft_sha512256_init, &ft_sha512_update,
		&ft_sha512256_close, {"-s", "-r", "-q", "-p"}, 128, 8, 8, 16, 1},
};

void	get_command(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < NB_CMD)
	{
		if (ft_strequ(argv[1], g_list_cmd[i].name))
		{
			g_list_cmd[i].handler(argc, argv, g_hash_cmd[i]);
			return ;
		}
		i++;
	}
	ssl_list_command(argv[1]);
}
