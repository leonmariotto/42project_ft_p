/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:02:56 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 15:44:34 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void        close_client(void)
{
  close(get_clientloopinfo()->sock);
  free(get_clientloopinfo());
  exit(0);
}
