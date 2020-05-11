/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:25:48 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/04 12:07:28 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int         trytoconnect(int sock, struct addrinfo *result)
{
  struct addrinfo *head;

  head = result;
  while (head)
  {
    if (connect(sock, head->ai_addr, head->ai_addrlen) != -1)
      break ;
    head = head->ai_next;
    close(sock);
  }
  if (head == NULL)
  {
    printf("Failed to connect\n");
    return (-1);
  }
  freeaddrinfo(result);
  return (0);
}
