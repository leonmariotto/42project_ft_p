/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:06:44 by lmariott          #+#    #+#             */
/*   Updated: 2019/01/31 14:52:47 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_realloc(void *ptr, int size, int newsize)
{
	char	*new;
	char	*str;
	int		i;

	str = (char*)ptr;
	if (!(new = (void*)malloc(sizeof(char) * newsize + 1)))
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	i = -1;
	while (++i < size)
		new[i] = str[i];
	while (i < newsize)
		new[i++] = '\0';
	if (ptr)
		free(ptr);
	return (new);
}
