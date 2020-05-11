/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 22:37:30 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 17:23:43 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int           server_loop(int mysock)
{
  struct sockaddr_in    client_addr;
  socklen_t             client_addr_size;
  int                   csock;
  t_list                *n;

  while(1)
  {
    client_addr_size = sizeof(client_addr);
    csock = accept(mysock, (struct sockaddr*)&client_addr, &client_addr_size);
    if (csock < 0)
    {
      ft_putendl_fd("accept call return an error\n", 2);
      return (-1);
    }
    else
    {
      if (!(n = ft_lstnew(&csock, sizeof(int))))
      {
        ft_putendl_fd("malloc call return an error", 2);
        return (2);
      }
      ft_lstadd(&get_serverloopinfo()->socket_used, n);
      printf("server: accepted a client connection from\n");
      printf("---------------------------------------------\n");
      printf("Client: IP=%s port=%d\n",
                inet_ntoa(client_addr.sin_addr),
                ntohs(client_addr.sin_port));
      printf("---------------------------------------------\n");
      if (fork_server(csock, client_addr) == 2)
        return (2);
    }
  }
}
