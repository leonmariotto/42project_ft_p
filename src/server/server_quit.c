/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_quit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:29:17 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/14 16:23:37 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int						server_quit(t_list *arg, int csock)
{
	ft_putendl_fd("Exit", csock);
	ft_lstdel(&arg, default_del);
	close_client();
	exit(0);
	return (0);
}
