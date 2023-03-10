# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlimones <jlimones@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 09:17:57 by jlimones          #+#    #+#              #
#    Updated: 2023/03/01 15:33:45 by jlimones         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
LIBFT = libft/libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC = 	src/push_swap.c \
		src/init_free_display.c \
		src/check_params.c \
		src/save_num.c \
		src/error.c \
		src/get_data_struck.c \
		src/check_ordered_num.c \
		moves/swappes.c \
		moves/push.c \
		moves/rotate.c \
		moves/reverse_rotate.c \
		sort/sort_3arg.c \
		sort/cal_target.c \
		sort/cost.c \
		sort/order.c \
		sort/algorithm.c \

SRC_CHECKER = 	src/init_free_display.c \
				src/check_params.c \
				src/save_num.c \
				src/error.c \
				src/get_data_struck.c \
				src/check_ordered_num.c \
				moves/swappes.c \
				moves/push.c \
				moves/rotate.c \
				moves/reverse_rotate.c \
				src/checker.c

AUTHOR = jlimones
DATE = 07/02/2023

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OBJ = $(SRC:.c=.o)
OBJCHECKER = $(CHECKER:.c=.o)

all: header $(NAME) $(CHECKER)
	@rm -rf .files_changed

header:
	@printf "%b" "$(OK_COLOR)"
	@echo "        ___  _____ ___  ___      _        "
	@echo "       /   |/ __  \|  \/  |     | |       "
	@echo "      / /| |\`' / /'| .  . | __ _| | _____ "
	@echo "     / /_| |  / /  | |\/| |/ _\` | |/ / _ \\"
	@echo "     \___  |./ /___| |  | | (_| |   <  __/"
	@echo "         |_/\_____/\_|  |_/\__,_|_|\_\___| v2"
	@echo
ifneq ($(HASH),)
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)@$(HASH)\n"
else
	@printf "%b" "$(OBJ_COLOR)Name:	$(WARN_COLOR)$(NAME)\n"
endif
	@printf "%b" "$(OBJ_COLOR)Author:	$(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date: 	$(WARN_COLOR)$(DATE)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)CC: 	$(WARN_COLOR)$(CC)\n\033[m"
	@printf "%b" "$(OBJ_COLOR)Flags: 	$(WARN_COLOR)$(FLAGS)\n\033[m"

$(NAME): $(SRC) $(OBJ)
	@make -C libft
	@gcc -o $(NAME) -g3 $(FLAGS) $(SRC) $(LIB) $(LIBFT)
	@printf "%b" "$(OK_COLOR)" "push_swap compilado\n"

$(CHECKER): $(SRC_CHECKER) $(OBJCHECKER)
	@gcc -o $(CHECKER) -g3 $(FLAGS) $(SRC_CHECKER) $(LIB) $(LIBFT)

%.o: %.c $(HEAD)
	@gcc $(FLAGS) -c $< -o $@

skiperror:
	@$(CC) -o $(NAME) $(SRC)
	@printf "%b" "$(ERROR_COLOR)" "Error\n"
	
clean: header
	@make clean -C libft
	@rm -f $(OBJ)

fclean: header clean
	@rm -f $(NAME)
	@make fclean -C libft
	@printf "%b" "$(OK_COLOR)" "fclean ejecutado correctamente\n"
	

re: fclean all