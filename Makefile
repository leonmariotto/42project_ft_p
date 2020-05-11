# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/14 14:00:58 by pemora            #+#    #+#              #
#    Updated: 2020/05/11 15:46:54 by lmariott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 := client
NAME2 := server

CC ?= gcc
CFLAGS ?= -Wall -Wextra -Werror

SRC1 := src/client/getservinfo.c\
        src/client/client_cd.c\
        src/client/simple_exec.c\
        src/client/signal.c\
        src/client/init.c\
        src/client/client_quit.c\
        src/client/client_ls.c\
        src/client/client_loop.c\
        src/client/get_clientinfo.c\
        src/client/exitclient.c\
        src/client/main.c\
        src/client/client_pwd.c\
        src/client/client_put.c\
        src/client/client_get.c\
        src/client/connect.c

SRC2 := src/server/server_pwd.c\
        src/server/getservinfo.c\
        src/server/serverclient_loop.c\
        src/server/server_putfile.c\
        src/server/server_loop.c\
        src/server/init.c\
        src/server/debug.c\
        src/server/server_getfile.c\
        src/server/server_cd.c\
        src/server/fork_server.c\
        src/server/main.c\
        src/server/server_quit.c\
        src/server/server_ls.c\
        src/server/server_interpreter.c\
        src/server/get_clientloopinfo.c\
        src/server/get_serverloopinfo.c\
        src/server/close_client.c\
        src/server/client_signal.c\
        src/server/server_signal.c\
        src/server/close_server.c\
        src/server/fstat_checks.c
 
LIBFTDIR := libft/
HDRDIR := include/

HDR := libft/libft.h	

OBJ1 := $(SRC1:.c=.o)
OBJ2 := $(SRC2:.c=.o)

LIBFT := libft/libft.a
LIBS := $(LIBFT)

all: $(NAME1) $(NAME2)

$(LIBFT):
	make -j 8 -C libft/

$(NAME1): $(LIBFT) $(OBJ1)
	$(CC) $(CFLAGS) -o $@ $(OBJ1) $(LIBS)

$(NAME2): $(LIBFT) $(OBJ2)
	$(CC) $(CFLAGS) -o $@ $(OBJ2) $(LIBS)

%.o: %.c $(HDR) Makefile
	$(CC) $(CFLAGS) -o $@ -c $< -I$(HDRDIR) -I$(LIBFTDIR)

clean:
	rm -f $(OBJ1)
	rm -f $(OBJ2)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
