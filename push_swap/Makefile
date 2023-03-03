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
CFLAGS = #-Wall -Werror -Wextra

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
		push_swap.c
SRCS := $(addprefix $(SRC_DIR),$(SRCS))

HEADER_DIR = include/
HEADER := push_swap.h
HEADER := $(addprefix $(HEADER_DIR),$(HEADER))

OBJS:=$(patsubst $(SRC_DIR)%.c,$(SRC_DIR)%.o,$(SRCS))

#_____PROGRAM_____#

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)AVISO:$(DEF_COLOR)$(BLUE)Buscando dependencia libft...$(DEF_COLOR)"
	@mv ../libft/libft.a $(NAME)
	@clear
	@echo "$(GREEN)Generando librería...$(DEF_COLOR)"
	@echo "$(YELLOW)Compilando $(WHITE) $(NAME) $(GREEN)\t✔️$(DEF_COLOR)"
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Librería generada$(DEF_COLOR)"

%.o: %.c
	@echo "$(YELLOW)Compilando $(WHITE) $< $(GREEN)\t✔️$(DEF_COLOR)"
	@$(CC) -c $(CFLAGS) -I $(HEADER_DIR) $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf exec

fclean: clean
	@rm -rf $(NAME)

re: fclean all

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: all

.PHONY: all re fclean clean