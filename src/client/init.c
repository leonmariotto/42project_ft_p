/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 01:09:37 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/04 11:35:13 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int       client_init(char *server, int port)
{
  int                 sock;
  struct addrinfo     *result;

  printf("==================== CLIENT INIT ===================\n");
  printf("1 - create a tcp stream socket\n");
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("socket call failed\n");
    exit(1);
  }
  printf("2 - getaddrinfo corresponding to hostname\n");
  if ((getservinfo(server, ft_itoa(port), &result)) != 0)
  {
    printf("getaddrinfo return an error\n");
    return (-1);
  }

  printf("3 : try to connect\n");
  if (trytoconnect(sock, result) != 0)
    return (-1);
  printf("==================== init done =====================\n");
  return sock;
}
