/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:09:38 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 12:08:47 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"
# include <stdio.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


int       client_init(char *server, int port);
int       getservinfo(char *host, char *service, struct addrinfo **result);
int       trytoconnect(int sock, struct addrinfo *result);
int       client_loop(int sock);
int       cli_signal(void);
void      close_client(void);

typedef struct      s_clientinfo
{
  int     sock;
}                   t_clientinfo;

t_clientinfo      *get_clientinfo(void);
void        exitclient(void);
int         simple_exec(t_list *tokens, int sock);
int         client_cd(t_list *arg, int sock);
int         client_ls(t_list *arg, int sock);
int         client_pwd(t_list *arg, int sock);
int         client_get(t_list *arg, int sock);
int         client_put(t_list *arg, int sock);
int         client_quit(t_list *arg, int sock);

#endif
