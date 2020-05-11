/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:36:22 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 21:08:44 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int       main(int ac, char **av)
{
  int port;
  int sock;

  if (ac != 3 || !(port = ft_atoi(av[2])))
  {
    printf("ft_p client Usage :\n$>./client <server> <host>\n");
    return (1);
  }
  if ((sock = client_init(av[1], port)) < 0)
    return (1);
  cli_signal();
  get_clientinfo()->sock = sock;
  return (client_loop(sock));
}
