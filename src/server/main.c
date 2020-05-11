/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:36:22 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 17:24:32 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void      print_usage(void)
{
  printf("ft_p server - Usage :\n$>./server <port>\n");
}

int       main(int ac, char **av)
{
  int port;
  int csock;
  int r;

  if (ac != 2 || !(port = ft_atoi(av[1])))
  {
    print_usage();
    return (1);
  }
  if ((csock = server_init(port)) < 0)
    return (1);
  server_signal();
  r = server_loop(csock);
  close(csock);
  return (r);
}
