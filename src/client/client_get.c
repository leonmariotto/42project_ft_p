/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:31:07 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/14 17:25:28 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "get_next_line.h"

static	int				availability(char *path)
{
	if (access(path, F_OK) == 0)
	{
		ft_putendl_fd("ERROR: File exist", 2);
		return (1);
	}
	return (0);
}

static	int				ptransfert(int sock, int fd, int size)
{
	int		n;
	int		r;
	char	buf[2048];
	int fdnull;

	fdnull = open("/dev/null", O_WRONLY);
	n = 0;
	while (n < size - 1)
	{
		write(fdnull, "\n", 1);
		if ((r = read(sock, buf, 2048)) < 0)
			return (ft_puterror("ERROR: read return an error"));
		write(fdnull, "\n", 1);
		if (r != write(fd, buf, r))
			return (ft_puterror("ERROR: write return an error"));
		write(fdnull, "\n", 1);
		n += r;
		ft_bzero(buf, 2048);
	}
	close(fdnull);
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
	ft_putstr_fd(path, 2);
	ft_putendl_fd(" : Processing transfer", 2);
	if (ptransfert(sock, fd, size))
		return (1);
	ft_putstr_fd(path, 2);
	ft_putendl_fd(" : End of transfer", 2);
	close(fd);
	return (0);
}

static	int				processing(char *path, int sock)
{
	char			*line;
	int				size;

	if (availability(path))
		return (1);
	ft_putstr_fd("get ", sock);
	ft_putendl_fd(path, sock);
	if (get_next_line(sock, &line) < 0)
		return (1);
	if (ft_strcmp(line, "SUCCESS"))
	{
		ft_putendl(line);
		ft_strdel(&line);
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

int								client_get(t_list *arg, int sock)
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
