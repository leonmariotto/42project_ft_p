/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_quit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:46:01 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 16:50:01 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int								client_quit(t_list *arg, int sock)
{
	ft_lstdel(&arg, default_del);
	(void)sock;
	exitclient();
	return (0);
}
