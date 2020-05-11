/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:33:28 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 00:14:40 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "get_next_line.h"

int           client_pwd(t_list *arg, int sock)
{
  char *line;

  if (ft_lstsize(arg) != 1)
  {
    ft_putendl_fd("pwd usage : pwd", 2);
    return (1);
  }
  ft_putendl_fd("pwd", sock);
  if (get_next_line(sock, &line) <= 0)
    return (1);
  ft_putendl(line);
  return (0);
}
