/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 20:32:10 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/10 21:32:12 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "get_next_line.h"

static int          parse(char *line)
{
  if (ft_strisspace(line))
    return (1);
  if (ft_strlen(line) >= 4096)
    return (1);
  return (0);
}

static t_list       *lexer(char *line)
{
  t_list      *tokens;
  char        **split;

  if (!(split = ft_strsplit(line, ' ')))
    tokens = NULL;
  else if (!(tokens = ft_arrtolst(split)))
  {
    ft_putendl_fd("malloc call return an error", 2);
    exitclient();
  }
  return (tokens);
}
  
static void      client_interp(char *line, int sock)
{
  t_list    *tokens;

  if (parse(line))
    return ;
  if (!(tokens = lexer(line)))
  {
    ft_putendl_fd("malloc error", 2);
    ft_strdel(&line);
    exitclient();
  }
  simple_exec(tokens, sock);
}

int       client_loop(int sock)
{
  char *line;

  while (1)
  {
    line = ft_prompt("client-$> ");
    client_interp(line, sock);
    ft_strdel(&line);
  }
  return (0);
}
