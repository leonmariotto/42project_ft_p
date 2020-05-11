/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getservinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:59:22 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/04 12:01:45 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int       getmyservinfo(char *host, char *service,
                    struct addrinfo **server_addr)
{
  struct addrinfo     hints;

  hints.ai_family = AF_INET;    /* Allow IPv4 or IPv6 */
  hints.ai_socktype = SOCK_STREAM; /* Datagram socket */
  hints.ai_flags = AI_PASSIVE | AI_NUMERICSERV;    /* For wildcard IP address */
  hints.ai_protocol = 0;          /* Any protocol */
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

/*
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("localhost");
  // server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  printf("Port number : %d\n", port); // debug
  server_addr.sin_port = htons(port);
*/

  if (getaddrinfo(host, service, &hints, server_addr) != 0)
    return (-1);
  printf("Server address: IP=%s port=%d\n",
                inet_ntoa(((struct sockaddr_in*)(*server_addr)->ai_addr)->sin_addr),
                ntohs(((struct sockaddr_in*)(*server_addr)->ai_addr)->sin_port));
  return (0);
}
