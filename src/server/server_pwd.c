/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:29:51 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 13:04:44 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int         server_pwd(t_list *arg, int csock)
{
  /*
  ** Send the result of the command to the client.
  ** Return an success or error message for the server.
  */
  t_clientloopinfo    *i;

  (void)arg;
  i = get_clientloopinfo();
  ft_putendl_fd(i->current_dir, csock);
  return (0);
}
