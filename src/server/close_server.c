/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:14:40 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 17:27:12 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void          close_server(void)
{
  t_serverloopinfo    *s;
  t_list              *head;

  s = get_serverloopinfo();
  head = s->socket_used;
  while (head)
  {
    close(*(int*)head->content);
    head = head->next;
  }
  close(s->server_socket);
  free(s);
}
