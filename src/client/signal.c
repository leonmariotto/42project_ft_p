/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 20:59:21 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 00:56:10 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <signal.h>

static void          signal_handler(int sig)
{
  if (sig == SIGINT || sig == SIGPIPE)
    exitclient();
}

int           cli_signal(void)
{
  signal(SIGINT, signal_handler);
  signal(SIGPIPE, signal_handler);
  return (0);
}
