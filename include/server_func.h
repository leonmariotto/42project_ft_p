/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_func.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:47:26 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 12:57:56 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_FUNC_H
# define SERVER_FUNC_H

static char const	*f_key[] =
{
	"cd",
  "ls",
  "get",
  "put",
  "pwd",
  "quit",
	NULL
};

static int			  (*f_func[])(t_list *arg, int csock) =
{
	&server_cd,
  &server_ls,
  &server_getfile,
  &server_putfile,
  &server_pwd,
  &server_quit
};

#endif
