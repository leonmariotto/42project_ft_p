/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:07:14 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 17:15:47 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>

static	void				signal_handler(int sig)
{
	if (sig == SIGINT || sig == SIGPIPE)
		close_client();
}

int									client_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGPIPE, signal_handler);
	return (0);
}
