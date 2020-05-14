/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 21:14:09 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 16:54:05 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_func.h"

int								simple_exec(t_list *tokens, int sock)
{
	int i;

	i = -1;
	while (fc_key[++i])
	{
		if (!ft_strcmp(fc_key[i], tokens->content))
			return (fc_func[i](tokens, sock));
	}
	ft_putendl_fd("Error: command not found", 2);
	return (1);
}
