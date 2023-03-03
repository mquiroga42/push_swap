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

#_____PROGRAM_____#

all: $(NAME)

$(NAME): libft push_swap
	@echo "$(GREEN)Compilando programa...$(DEF_COLOR)"
	@echo "$(YELLOW)Compilando $(WHITE) exec $(GREEN)\t✔️$(DEF_COLOR)"
	@$(CC) -g3 no_main.c push_swap/$(NAME) -o exec
	@echo "$(GREEN)Programa compilado$(DEF_COLOR)"

push_swap:
	@make -C push_swap

libft:
	@make -C libft

clean:
	@make -C push_swap clean
	@make -C libft clean
	@rm -rf exec *.o binary/*.o

fclean: clean
	@make -C push_swap fclean
	@make -C libft fclean
	@rm -rf exec binary/*.a *.a
	@clear

re: fclean all

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: all

.PHONY: all re clean push_swap libft