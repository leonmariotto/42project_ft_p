/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:17:03 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 00:11:38 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "get_next_line.h"

int             client_cd(t_list *arg, int sock)
{
  char *line;

  if (ft_lstsize(arg) != 2)
  {
    ft_putendl_fd("cd usage : cd <dir>", 2);
    return (1);
  }
  ft_putstr_fd("cd ", sock);
  ft_putendl_fd((char*)arg->next->content, sock);
  if (get_next_line(sock, &line) <= 0)
    return (1);
  ft_putendl(line);
  return (0);
}
