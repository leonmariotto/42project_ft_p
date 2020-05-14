/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:27:40 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/14 17:23:24 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "get_next_line.h"

static	int						availability(char *path)
{
	struct stat s;

	if (access(path, F_OK) < 0)
	{
		ft_putendl_fd("ERROR: File not exist", 2);
		return (1);
	}
	if (access(path, R_OK) < 0)
	{
		ft_putendl_fd("ERROR: Operation not permitted", 2);
		return (1);
	}
	if (lstat(path, &s) < 0)
		return (1);
	if ((s.st_mode & S_IFMT) == S_IFLNK)
	{
		ft_putendl_fd("ERROR: Symbolique link not allowed", 2);
		return (1);
	}
	if ((s.st_mode & S_IFMT) != S_IFREG)
	{
		ft_putendl_fd("ERROR: Not a regular file", 2);
		return (1);
	}
	return (0);
}

static	int						getfilesize(char *path, int sock)
{
	struct stat s;

	(void)sock;
	if (lstat(path, &s) < 0)
	{
		ft_putendl_fd("ERROR: lstat call return an error", 2);
		return (1);
	}
	return (s.st_size);
}

static	int						sendfile(char *path, int sock, int size)
{
	int			r;
	int			c;
	char		buf[2048];
	int			fd;

	c = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (ft_puterror("ERROR: open return an error\n\n"));
	while (c < size - 1)
	{
		if ((r = read(fd, buf, 2048)) == -1)
			return (ft_puterror("ERROR: read return an error"));
		if (r != write(sock, buf, r))
			return (ft_puterror("ERROR: write return an error"));
		c += r;
		ft_bzero(buf, 2048);
	}
	close(fd);
	return (0);
}

static	int						client_getservavailable(t_list *arg, int csock)
{
	char *line;
	int size;

	if (get_next_line(csock, &line) < 0)
		return (-1);
	if (ft_strcmp(line, "SUCCESS"))
	{
		ft_putendl(line);
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	if ((size = getfilesize((char*)arg->content, csock)) == -1)
		return (-1);
	ft_putnbr_fd(size, csock);
	ft_putchar_fd('\n', csock);
	if (get_next_line(csock, &line) <= 0)
		return (-1);
	ft_putendl(line);
	ft_strdel(&line);
	return (size);
}

int										client_put(t_list *arg, int csock)
{
	int			size;
	char		*line;

	if (ft_lstsize(arg) != 2)
	{
		ft_putendl_fd("put usage : put <file>", 2);
		return (1);
	}
	arg = arg->next;
	if (ft_strchr((char*)arg->content, '/'))
	{
		ft_putendl_fd("ERROR: Forbidden charactere : \"/\"", 2);
		return (1);
	}
	if (availability((char*)arg->content))
		return (1);
	ft_putstr_fd("put ", csock);
	ft_putendl_fd((char*)arg->content, csock);
	if ((size = client_getservavailable(arg, csock)) < 0
				|| sendfile((char*)arg->content, csock, size) == -1
				|| get_next_line(csock, &line) <= 0)
		return (1);
	ft_putendl(line);
	ft_strdel(&line);
	return (0);
}
