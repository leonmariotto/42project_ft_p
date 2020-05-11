/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 15:05:32 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/07 15:16:34 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

char        *ft_prompt(char *prompt_msg)
{
  char *line;

  write(1, prompt_msg, ft_strlen(prompt_msg));
  get_next_line(0, &line);
  return (line);
}
