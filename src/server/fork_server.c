/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 15:31:21 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 17:42:45 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int         init_clientloopinfo(int sock)
{
  t_clientloopinfo    *i;
  char                *buf;

  if (!(i = get_clientloopinfo()))
  {
    ft_putendl_fd("malloc call return an error", 2);
    return (1);
  }
  buf = NULL;
  if ((buf = getcwd(buf, 0)) == NULL)
  {
    ft_putendl_fd("getcwd call return an error", 2);
    return (1);
  }
  i->current_dir = buf; 
  if(!(i->init_dir = ft_strdup(buf)))
  {
    ft_putendl_fd("getcwd call return an error", 2);
    return (1);
  }
  i->sock = sock;
  return (0);
}

int         fork_server(int sock, struct sockaddr_in client_addr)
{
  int     r;

  r = fork();
  if (r < 0)
  {
    ft_putendl_fd("Fork call return an error", 2);
    return (2);
  }
  else if (!r)
  {
    if (init_clientloopinfo(sock) != 0)
      return (1);
    client_signal();
    return (serverclientloop(client_addr));
  }
  else
  {
    return (0);
  }
}
