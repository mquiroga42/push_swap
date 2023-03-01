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
	@echo "$(GREEN)Compilando programa...$(DEF_COLOR)"
	@$(CC) -g3 no_main.c *.a -o exec
	@echo "$(GREEN)Programa compilado$(DEF_COLOR)"

$(NAME):
	@echo "$(GREEN)Compilando libft...$(DEF_COLOR)"
	@make -C libft
	@mv libft/libft.a libft.a
	@echo "$(GREEN)libft compilado$(DEF_COLOR)"
	@echo "$(GREEN)Compilando push_swap...$(DEF_COLOR)"
	@make -C push_swap
	@mv push_swap/push_swap.a push_swap.a
	@echo "$(GREEN)push_swap compilado$(DEF_COLOR)"

clean:
	@make -C push_swap clean
	@make -C libft clean
	@rm -rf exec

fclean: clean
	@make -C push_swap fclean
	@make -C libft fclean
	@rm -rf exec *.a
	@clear

re: fclean all

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: all

.PHONY: all clean