/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:09:38 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 12:13:36 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <sys/stat.h>
# include <fcntl.h>

# define SERVER_HOST "localhost"
# define SERVER_IP "127.0.0.1"

void      debug_printoctet(char *ptr, int n);
void      debug_printaddrinfo(struct addrinfo *res);
int       server_init(int port);
int       server_loop(int csock);
int       getmyservinfo(char *host, char *service,
              struct addrinfo **server_addr);
int       fork_server(int csock, struct sockaddr_in client_addr);
int       serverclientloop(struct sockaddr_in client_addr);
int       server_ls(t_list *arg, int csock);
int       server_cd(t_list *arg, int csock);
int       server_getfile(t_list *arg, int csock);
int       server_putfile(t_list *arg, int csock);
int       server_pwd(t_list *arg, int csock);
int       server_quit(t_list *arg, int csock);
int       server_interpreter(char *line, int csock);
void      close_client(void);
int       client_signal(void);
int        fstat_checks(char *path, int sock);

typedef struct      s_clientloopinfo
{
  char      *msg;
  char      *current_dir;
  char      *init_dir;
  int       sock;
}                   t_clientloopinfo;

typedef struct      s_serverloopinfo
{
  t_list    *socket_used;
  int       server_socket;
}                   t_serverloopinfo;

t_clientloopinfo        *get_clientloopinfo(void);
t_serverloopinfo        *get_serverloopinfo(void);
int           server_signal(void);
void          close_server(void);

#endif
