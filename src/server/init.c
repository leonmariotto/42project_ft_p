/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 22:25:25 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 17:01:20 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int       server_init(int port)
{
  int                 mysock;
  struct addrinfo     *server_addr;

  printf("==================== SERVER INIT ===================\n");
  printf("1 - create a tcp stream socket\n");
  if ((mysock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    printf("socket call failed");
    return (-1);
  }
  printf("2 : fill server_addr with host ip and port info\n");
  if ((getmyservinfo("localhost", ft_itoa(port), &server_addr)) < 0)
  {
    printf("getaddrinfo call return an error");
    return (-1);
  }
  printf("3 : bind socket to server address\n");
  printf("Server address: IP=%s port=%d\n",
                inet_ntoa(((struct sockaddr_in*)server_addr->ai_addr)->sin_addr),
                ntohs(((struct sockaddr_in*)server_addr->ai_addr)->sin_port));
  if ((bind(mysock, server_addr->ai_addr, server_addr->ai_addrlen)) < 0)
  {
    printf("bind call return an error");
    return (-1);
  }
  printf("4 : server is listening\n");
  if((listen(mysock, 5)) < 0)
  {
    printf("listen call return an error");
    return (-1);
  }
  get_serverloopinfo()->server_socket = mysock;
  printf("==================== init done  ====================\n\n");
  return (mysock);
}
