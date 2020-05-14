/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverclient_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 15:38:40 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/14 16:59:51 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "get_next_line.h"

int						serverclientloop(struct sockaddr_in client_addr)
{
	char		*line;
	int			r;

	while (1)
	{
		if (get_next_line(get_clientloopinfo()->sock, &line) <= 0)
		{
			ft_putstr_fd("End connection with ", 2);
			ft_putendl_fd(inet_ntoa(client_addr.sin_addr), 2);
			close_client();
			return (1);
		}
		r = server_interpreter(line, get_clientloopinfo()->sock);
		ft_strdel(&line);
		if (r == 1)
			printf("%s: %s\n", inet_ntoa(client_addr.sin_addr), "ERROR");
		if (r == 2)
			close_client();
	}
}
