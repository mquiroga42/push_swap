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
CFLAGS = -g3 #-fsanitize=address #-Wall -Werror -Wextra

#_____CONF_____#

MAKEFLAGS += --no-print-directory

#_____COLORS_____#

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#_____OBJS_____#

SRC_DIR = src/
SRCS := is_error.c\
		push_swap.c \
		list_utils.c
SRCS := $(addprefix $(SRC_DIR),$(SRCS))

HEADER_DIR = include/
HEADER := push_swap.h
HEADER := $(addprefix $(HEADER_DIR),$(HEADER))

OBJS:=$(patsubst $(SRC_DIR)%.c,$(SRC_DIR)%.o,$(SRCS))

#_____PROGRAM_____#

all: $(NAME)

$(NAME): libft $(OBJS)
	@mv modules/libft/libft.a $(NAME)
	@clear
	@echo "$(GREEN)Generando librería...$(DEF_COLOR)" && sleep 0.5 && clear
	@echo "$(YELLOW)Compilando $(WHITE) $(NAME) $(GREEN)\t✔️$(DEF_COLOR)" && sleep 0.5  && clear
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Librería generada$(DEF_COLOR)" && sleep 0.5 && clear
	@make exec

libft:
	@echo "$(GREEN) Comilando $(YELLOW)libft...$(DEF_COLOR)"
	@make -C modules/libft bonus

exec:
	@echo "$(GREEN)Generando programa...$(DEF_COLOR)" && sleep 0.5  && clear
	@echo "$(YELLOW)Compilando $(WHITE) exec $(GREEN)\t✔️$(DEF_COLOR)" && sleep 0.5  && clear
	@gcc -g3 $(CFLAGS) no_main.c $(NAME) -o push_swap
	@echo "$(GREEN)Programa generado$(DEF_COLOR)" && sleep 0.5 && clear

%.o: %.c
	@echo "$(YELLOW)Compilando $(WHITE) $< $(GREEN)\t✔️$(DEF_COLOR)"
	@$(CC) -c $(CFLAGS) -I $(HEADER_DIR) $< -o $@

clean:
	@make -C modules/libft clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C modules/libft fclean
	@$(RM) $(NAME) push_swap

re: fclean all

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: all

.PHONY: all re fclean clean