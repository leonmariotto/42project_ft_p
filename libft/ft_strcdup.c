/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:11:48 by lmariott          #+#    #+#             */
/*   Updated: 2018/11/21 19:07:08 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(char *str, char c)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (!(line = ft_strnew(i + 1)))
		return (NULL);
	line = ft_memcpy(line, str, (size_t)i);
	line[i + 1] = '\0';
	return (line);
}
