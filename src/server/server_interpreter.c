/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_interpreter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 18:00:53 by lmariott          #+#    #+#             */
/*   Updated: 2020/05/11 00:54:17 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_func.h"

static int           parser(char *line)
{
  if (ft_strisspace(line) == 1)
    return (1);
  if (ft_strlen(line) > 4096)
    return (-1);
  
  return (0);
}

static t_list        *lexer(char *line)
{
  t_list      *tokens;
  char        **split;

  if (!(split = ft_strsplit(line, ' ')))
    tokens = NULL;
  else if (!(tokens = ft_arrtolst(split)))
  {
    ft_putendl_fd("ERROR: malloc call return an error", 2);
    close_client();
  }
  return (tokens);
}

static int           simple_cmd_exec(t_list *tokens, int csock)
{
  int i;

  i = -1;
  while (f_key[++i])
  {
    if (!ft_strcmp(f_key[i], tokens->content))
      return (f_func[i](tokens, csock));
  }
  ft_putendl_fd("ERROR: command not found", csock);
  return (1);
}

int          server_interpreter(char *line, int csock)
{
  t_list  *tokens;
  int     r;

  if (parser(line))
    return (1);
  if (!(tokens = lexer(line)))
    return (1);
  r = simple_cmd_exec(tokens, csock);
  ft_lstdel(&tokens, default_del);
  return (r);
}
