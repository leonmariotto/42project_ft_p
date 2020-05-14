/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstat_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 00:40:03 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 17:45:29 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <sys/types.h>
#include <sys/stat.h>

int						fstat_checks(char *path, int sock)
{
	struct stat s;

	if (access(path, F_OK) < 0)
	{
		ft_putendl_fd("ERROR: Directory not exist", sock);
		return (1);
	}
	if (access(path, R_OK) < 0)
	{
		ft_putendl_fd("ERROR: Operation not permitted", sock);
		return (1);
	}
	if (lstat(path, &s) < 0)
	{
		ft_putendl_fd("ERROR: lstat call return an error", sock);
		return (1);
	}
	if ((s.st_mode & S_IFMT) == S_IFLNK)
	{
		ft_putendl_fd("ERROR: Symbolique link not allowed", sock);
		return (1);
	}
	return (0);
}
