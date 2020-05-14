/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:24:46 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/14 17:33:14 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static	int		ft_puterror(char *error, int csock)
{
	ft_putendl_fd(error, csock);
	return (1);
}

int						server_cd(t_list *arg, int csock)
{
	t_clientloopinfo *c;

	c = get_clientloopinfo();
	arg = arg->next;
	if (!ft_strcmp(c->current_dir, c->init_dir)
			&& !ft_strcmp((char*)arg->content, ".."))
		return (ft_puterror("ERROR : Forbidden directory", csock));
	if (ft_strchr((char*)arg->content, '/'))
		return (ft_puterror("ERROR : Forbidden charactere : \"/\"", csock));
	if (fstat_checks((char*)arg->content, csock))
		return (1);
	if (chdir((char*)arg->content) < 0)
		return(ft_puterror("ERROR : chdir returned an error", csock));
	free(c->current_dir);
	c->current_dir = getcwd(NULL, 0);
	ft_putendl_fd("SUCCESS", csock);
	return (0);
}
