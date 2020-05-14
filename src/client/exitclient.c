/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitclient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 21:09:06 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/14 16:47:47 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void								exitclient(void)
{
	t_clientinfo *c;

	c = get_clientinfo();
	close(c->sock);
	free(c);
	exit(0);
}
