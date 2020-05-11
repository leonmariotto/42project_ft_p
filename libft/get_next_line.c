/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:33:23 by lmariott          #+#    #+#             */
/*   Updated: 2019/01/31 14:49:49 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			move(void **ptr)
{
	char	*tmp;
	char	*str;

	str = (char*)*ptr;
	tmp = ft_strdup(ft_strchr(str, '\n') + 1);
	free(*ptr);
	*ptr = tmp;
}

static t_list	*ft_multiple_fd(t_list **lst_fd, size_t fd)
{
	t_list	*head;

	if (!*lst_fd)
	{
		*lst_fd = ft_lstnew(NULL, 0);
		(*lst_fd)->content_size = fd;
		return (*lst_fd);
	}
	head = *lst_fd;
	while (head)
	{
		if (head->content_size == fd)
			return (head);
		head = head->next;
	}
	head = ft_lstnew(NULL, 0);
	head->content_size = fd;
	ft_lstadd(lst_fd, head);
	return (head);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst_fd;
	t_list			*head;
	char			buff[BUFF_SIZE + 1];
	int				r;
	int				i;

	if (!line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	head = ft_multiple_fd(&lst_fd, (size_t)fd);
	while ((r = read(fd, buff, BUFF_SIZE)))
	{
		buff[r] = '\0';
		i = ft_strlen(head->content);
		if (!(head->content = ft_realloc(head->content, i, i + r + 1)))
			return (-1);
		head->content = ft_strcat(head->content, buff);
		if (ft_strchr(head->content, '\n'))
			break ;
	}
	if (r < BUFF_SIZE && !ft_strlen(head->content))
		return (0);
	*line = ft_strcdup(head->content, '\n');
	(ft_strchr(head->content, '\n')) ? (move(&head->content)) :
		(ft_strclr(head->content));
	return (1);
}
