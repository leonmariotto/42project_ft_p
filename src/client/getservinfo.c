/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getservinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:18:29 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/14 16:47:18 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

/*
** J'ai utilisé getaddrinfo pour remplacer l'emploi de
** gethostbyname. Ce dernier est déprécié (C'est indiqué
** dans le man)
** hints sers aux options de getaddrinfo
*/

int				getservinfo(char *host, char *service, struct addrinfo **result)
{
	struct addrinfo				*hints;

	if (!(hints = (struct addrinfo*)malloc(sizeof(struct addrinfo))))
		return (-1);
	hints->ai_family = AF_INET;
	hints->ai_socktype = SOCK_STREAM;
	hints->ai_flags = 0;
	hints->ai_protocol = 0;
	if (getaddrinfo(host, service, hints, result) != 0)
		return (-1);
	printf("Server address: IP=%s port=%d\n",
			inet_ntoa(((struct sockaddr_in*)(*result)->ai_addr)->sin_addr),
			ntohs(((struct sockaddr_in*)(*result)->ai_addr)->sin_port));
	free(hints);
	return (0);
}
