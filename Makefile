# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyberoot <cyberoot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 12:33:56 by cyberoot          #+#    #+#              #
#    Updated: 2023/01/23 08:54:08 by cyberoot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_____VARIABLES_____#

NAME = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

#_____OBJS_____#

SRCS:=$(wildcard src/*.c)
HEADERS:=$(wildcard include/*.h)
OBJS:=$(patsubst src/%.c,src/%.o,$(SRCS))

#_____PROGRAM_____#

all: $(NAME)
	@$(CC) no_main.c $(NAME) -o exec

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $^

clean:
	@rm -rf $(OBJS)
	@rm -rf exec

fclean: clean
	@rm -rf $(NAME)

re: fclean all

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: all

.PHONY: all clean