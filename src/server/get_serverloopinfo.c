/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_serverloopinfo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:53:30 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 16:56:22 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_serverloopinfo        *get_serverloopinfo(void)
{
  static t_serverloopinfo     *s;

  if (s)
    return (s);
  if (!(s = (t_serverloopinfo*)ft_memalloc(sizeof(t_serverloopinfo))))
    return (NULL);
  return (s);
}
