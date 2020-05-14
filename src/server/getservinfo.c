/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getservinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:59:22 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 17:52:00 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int				getmyservinfo(char *host, char *service,
		struct addrinfo **server_addr)
{
	struct addrinfo				hints;

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE | AI_NUMERICSERV;
	hints.ai_protocol = 0;
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;
	if (getaddrinfo(host, service, &hints, server_addr) != 0)
		return (-1);
	printf("Server address: IP=%s port=%d\n",
			inet_ntoa(((struct sockaddr_in*)(*server_addr)->ai_addr)->sin_addr),
			ntohs(((struct sockaddr_in*)(*server_addr)->ai_addr)->sin_port));
	return (0);
}
