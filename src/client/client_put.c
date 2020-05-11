/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:27:40 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 22:35:35 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int         client_put(t_list *arg, int sock)
{
  if (ft_lstsize(arg) != 2)
  {
    ft_putendl_fd("put usage : put <file>", 2);
    return (1);
  }
  ft_putendl_fd("Ceci est un put", sock);
  return (0);
}
