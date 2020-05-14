/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_putfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:27:45 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/14 17:28:14 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "get_next_line.h"

static	int				availability(char *path, int sock)
{
	if (access(path, F_OK) == 0)
	{
		ft_putendl_fd("ERROR: File exist", sock);
		return (1);
	}
	return (0);
}

static	int				ptransfert(int sock, int fd, int size)
{
	int		n;
	int		r;
	char	buf[2048];

	n = 0;
	while (n < size - 1)
	{
		if ((r = read(sock, buf, 2047)) <= 0)
		{
			ft_putendl_fd("ERROR: read return an error", 2);
			return (1);
		}
		if (r != write(fd, buf, r))
		{
			ft_putendl_fd("ERROR: write return an error", 2);
			return (1);
		}
		n += r;
		ft_bzero(buf, 2048);
	}
	return (0);
}

static	int				transfert(char *path, int sock, int size)
{
	int				fd;

	if ((fd = open(path, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO)) < 0)
	{
		ft_putendl_fd("ERROR: open return an error", 2);
		return (1);
	}
	ft_putstr_fd(path, sock);
	ft_putendl_fd(" : Processing transfer", sock);
	if (ptransfert(sock, fd, size))
		return (1);
	ft_putstr_fd(path, sock);
	ft_putendl_fd(" : End of transfer", sock);
	close(fd);
	return (0);
}

static	int				processing(char *path, int sock)
{
	char			*line;
	int				size;

	if (availability(path, sock))
		return (1);
	ft_putendl_fd("SUCCESS", sock);
	if (get_next_line(sock, &line) <= 0)
		return (1);
	size = ft_atoi(line);
	ft_strdel(&line);
	if (transfert(path, sock, size))
		return (1);
	return (0);
}

int								server_putfile(t_list *arg, int sock)
{
	if (processing((char*)arg->next->content, sock))
		return (1);
	return (0);
}
