/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:24:40 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 23:13:12 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "get_next_line.h"

int         client_ls(t_list *arg, int sock)
{
  char    *line;

  if (ft_lstsize(arg) != 1)
  {
    ft_putendl_fd("ls usage : ls\nprint the CURRENT directory", 2);
    return (1);
  }
  ft_putendl_fd("ls", sock);
  if (get_next_line(sock, &line) <= 0)
    return (1);
  ft_putendl(line);
  return (0);
}
