/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_func.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:47:26 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 22:45:25 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_FUNC_H
# define SERVER_FUNC_H

static char const	*fc_key[] =
{
	"cd",
  "ls",
  "get",
  "put",
  "pwd",
  "quit",
	NULL
};

static int			  (*fc_func[])(t_list *arg, int sock) =
{
	&client_cd,
  &client_ls,
  &client_get,
  &client_put,
  &client_pwd,
  &client_quit
};

#endif
