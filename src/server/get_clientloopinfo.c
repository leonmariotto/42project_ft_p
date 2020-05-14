/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clientloopinfo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 11:58:46 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 17:33:30 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_clientloopinfo						*get_clientloopinfo(void)
{
	static t_clientloopinfo *i = NULL;

	if (i)
		return (i);
	if (!(i = (t_clientloopinfo*)ft_memalloc(sizeof(t_clientloopinfo))))
		return (NULL);
	return (i);
}
