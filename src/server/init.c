/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 22:25:25 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/14 17:30:02 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static	int		ft_puterror(char *error)
{
	ft_putendl_fd(error, 2);
	return (-1);
}

int						server_init(int port)
{
	int									mysock;
	struct addrinfo			*server_addr;
	char								*port_itoa;

	printf("==================== SERVER INIT ===================\n");
	printf("1 - create a tcp stream socket\n");
	if ((mysock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return (ft_puterror("socket call failed"));
	printf("2 : fill server_addr with host ip and port info\n");
	if (!(port_itoa = ft_itoa(port)))
		return (ft_puterror("ft_itoa call return an error"));
	if ((getmyservinfo("localhost", port_itoa, &server_addr)) < 0)
		return (ft_puterror("getaddrinfo call return an error"));
	free(port_itoa);
	printf("3 : bind socket to server address\n");
	if ((bind(mysock, server_addr->ai_addr, server_addr->ai_addrlen)) < 0)
		return (ft_puterror("bind call return an error"));
	printf("4 : server is listening\n");
	if ((listen(mysock, 5)) < 0)
		return (ft_puterror("listen call return an error"));
	get_serverloopinfo()->server_socket = mysock;
	get_serverloopinfo()->addr_info = server_addr;
	printf("==================== init done  ====================\n\n");
	return (mysock);
}
