/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_getfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:26:36 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 17:32:47 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static	int						availability(char *path, int sock)
{
	struct stat s;

	if (access(path, F_OK) < 0)
	{
		ft_putendl_fd("ERROR: File not exist", sock);
		return (1);
	}
	if (access(path, R_OK) < 0)
	{
		ft_putendl_fd("ERROR: Operation not permitted", sock);
		return (1);
	}
	if (lstat(path, &s) < 0)
		return (1);
	if ((s.st_mode & S_IFMT) == S_IFLNK)
	{
		ft_putendl_fd("ERROR: Symbolique link not allowed", sock);
		return (1);
	}
	if ((s.st_mode & S_IFMT) != S_IFREG)
	{
		ft_putendl_fd("ERROR: Not a regular file", sock);
		return (1);
	}
	return (0);
}

static	int						getfilesize(char *path, int sock)
{
	struct stat s;

	if (lstat(path, &s) < 0)
	{
		ft_putendl_fd("ERROR: lstat call return an error", sock);
		return (1);
	}
	return (s.st_size);
}

static	int						ft_puterror(char *error)
{
	ft_putendl_fd(error, 2);
	return (1);
}

static	int						sendfile(char *path, int sock, int size)
{
	int			r;
	int			c;
	char		buf[2048];
	int			fd;

	c = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (ft_puterror("ERROR: open return an error"));
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

int										server_getfile(t_list *arg, int csock)
{
	int			size;

	arg = arg->next;
	if (ft_strchr((char*)arg->content, '/'))
	{
		ft_putendl_fd("ERROR: Forbidden charactere : \"/\"", csock);
		return (1);
	}
	if (availability((char*)arg->content, csock))
		return (1);
	ft_putendl_fd("SUCCESS", csock);
	if ((size = getfilesize((char*)arg->content, csock)) == -1)
		return (1);
	ft_putnbr_fd(size, csock);
	ft_putchar_fd('\n', csock);
	if (sendfile((char*)arg->content, csock, size) == -1)
		return (1);
	return (0);
}
