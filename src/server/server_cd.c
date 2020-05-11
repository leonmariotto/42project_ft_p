/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:24:46 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 00:42:56 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int          server_cd(t_list *arg, int csock)
{
  t_clientloopinfo *c;

  c = get_clientloopinfo();
  arg = arg->next;
  if (!ft_strcmp(c->current_dir, c->init_dir)
      && !ft_strcmp((char*)arg->content, ".."))
  {
    ft_putendl_fd("ERROR : Forbidden directory", csock);
    return (1);
  }
  if (ft_strchr((char*)arg->content, '/'))
  {
    ft_putendl_fd("ERROR : Forbidden charactere : \"/\"", csock);
    return (1);
  }
  // TODO fstats check, access, permission, symbolic link
  if (fstat_checks((char*)arg->content, csock))
    return (1);
  if (chdir((char*)arg->content) < 0)
  {
    ft_putendl_fd("ERROR : chdir returned an error", csock);
    return (1);
  }
  c->current_dir = getcwd(NULL, 0);
  ft_putendl_fd("SUCCESS", csock);
  return (0);
}
