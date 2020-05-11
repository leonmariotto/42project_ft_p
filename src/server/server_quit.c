/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_quit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:29:17 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 13:06:38 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int         server_quit(t_list *arg, int csock)
{
  /*
  ** Send the result of the command to the client.
  ** Return an success or error message for the server.
  */
  (void)arg;
  ft_putendl_fd("Exit", csock);
  close(csock);
  exit(0);
  return (0);
}
