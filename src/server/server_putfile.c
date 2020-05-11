/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_putfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:27:45 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 13:02:38 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int         server_putfile(t_list *arg, int csock)
{
  /*
  ** Send the result of the command to the client.
  ** Return an success or error message for the server.
  */
  (void)arg;
  write(csock, "put\n", 4);
  return (0);
}
