/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:31:07 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 14:48:22 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "get_next_line.h"

static int        availability(char *path)
{
  if (access(path, F_OK) == 0)
  {
    ft_putendl_fd("ERROR: File exist", 2);
    return (1);
  }
  return (0);
}

/*
** TODO find proper solution to buffer
** bug. (\n after read)
*/

static int           transfert(char *path, int sock, int size)
{
  int   n;
  int   r;
  int   fd;
  int   fdnull;
  char  buf[2048];

  if ((fd = open(path, O_CREAT|O_RDWR, S_IRWXU|S_IRWXG|S_IRWXO)) < 0)
  {
    ft_putendl_fd("ERROR: open return an error", 2);
    return (1);
  }
  if ((fdnull = open("/dev/null", O_RDONLY)) < 0)
  {
    ft_putendl_fd("ERROR: open return an error", 2);
    return (1);
  }
  ft_putstr_fd(path, 2);
  ft_putendl_fd(" : Processing transfer", 2);
  n = 0;
  while (n < size - 1)
  {
    if ((r = read(sock, buf, 2048)) < 0)
    {
      ft_putendl_fd("ERROR: read return an error", 2);
      return (1);
    }
    write(fdnull, "After read\n", 11);
    if (r != write(fd, buf, r))
    {
      ft_putendl_fd("ERROR: write return an error", 2);
      return (1);
    }
    n += r;
    ft_bzero(buf, 2048);
  }
  ft_putstr_fd(path, 2);
  ft_putendl_fd(" : End of transfer", 2);
  close(fd);
  close(fdnull);
  return (0);
}

static int           processing(char *path, int sock)
{
  char  *line;
  int   size;

  if (availability(path))
    return (1);
  ft_putstr_fd("get ", sock);
  ft_putendl_fd(path, sock);
  if (get_next_line(sock, &line) < 0)
    return (1);
  if (ft_strcmp(line, "SUCCESS"))
  {
    ft_putendl(line);
    return (1);
  }
  ft_strdel(&line);
  if (get_next_line(sock, &line) < 0)
    return (1);
  size = ft_atoi(line);
  ft_strdel(&line);
  if (transfert(path, sock, size))
    return (1);
  return (0);
}

int           client_get(t_list *arg, int sock)
{
  if (ft_lstsize(arg) != 2)
  {
    ft_putendl_fd("get usage : get <file>", 2);
    return (1);
  }
  if (processing((char*)arg->next->content, sock))
    return (1);
  return (0);
}
