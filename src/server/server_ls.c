/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:20:20 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 00:42:31 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <sys/types.h>
#include <dirent.h>

int         server_ls(t_list *arg, int csock)
{
  /*
  ** Send the result of the command to the client.
  ** Return an success or error message for the server.
  */
  DIR               *d;
  struct dirent     *di;

  (void)arg;
  // TODO fstats check, access, permission, symbolic link
  if (fstat_checks(".", csock))
    return (1);
  d = opendir(".");
  while ((di = readdir(d)))
  {
    ft_putstr_fd(di->d_name, csock);
    ft_putchar_fd(' ', csock);
  }
  ft_putchar_fd('\n', csock);
  closedir(d);
  return (0);
}
