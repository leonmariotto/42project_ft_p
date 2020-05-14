/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 01:09:37 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/14 17:13:07 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int							client_init(char *server, int port)
{
	int									sock;
	struct addrinfo			*result;
	char								*port_itoa;

	printf("==================== CLIENT INIT ===================\n");
	printf("1 - create a tcp stream socket\n");
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		exit(1);
	printf("2 - getaddrinfo corresponding to hostname\n");
	if (!(port_itoa = ft_itoa(port)))
		return (-1);
	if ((getservinfo(server, port_itoa, &result)) != 0)
	{
		printf("getaddrinfo return an error\n");
		return (-1);
	}
	free(port_itoa);
	get_clientinfo()->addr_info = result;
	printf("3 : try to connect\n");
	if (trytoconnect(sock, result) != 0)
		return (-1);
	printf("==================== init done =====================\n");
	return (sock);
}
