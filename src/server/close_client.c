/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:02:56 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/14 16:23:56 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void				close_client(void)
{
	// TODO notify connection closed, put info_addr in the struct
	ft_putendl_fd("Close client", 2);
	close(get_clientloopinfo()->sock);
	free(get_clientloopinfo()->init_dir);
	free(get_clientloopinfo()->current_dir);
//	free(&get_clientloopinfo()->addr_info);
	free(get_clientloopinfo());
	exit(0);
}
