/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clientinfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 21:02:12 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 16:45:29 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_clientinfo							*get_clientinfo(void)
{
	static t_clientinfo		*c = NULL;

	if (c)
		return (c);
	if (!(c = (t_clientinfo*)ft_memalloc(sizeof(t_clientinfo))))
		return (NULL);
	return (c);
}
