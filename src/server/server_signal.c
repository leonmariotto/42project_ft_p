/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:42:02 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 00:47:24 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>

static void          signal_handler(int sig)
{
  if (sig == SIGINT || sig == SIGPIPE)
    close_server();
}

int           server_signal(void)
{
  signal(SIGINT, signal_handler);
  signal(SIGPIPE, signal_handler);
  return (0);
}
