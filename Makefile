# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 13:24:47 by altikka           #+#    #+#              #
#    Updated: 2022/04/29 15:41:43 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCS = -I libft/ -I includes/

SRC_DIR = src/
SRCS = $(SRC_DIR)ft_printf.c \
	   $(SRC_DIR)print_shop.c \
	   $(SRC_DIR)utilities.c \
	   $(SRC_DIR)press.c

OBJ_DIR = obj/
OBJ_LIBFT = libft/*.o
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o) $(OBJ_LIBFT)

FLGS = -Wall -Wextra -Werror

NCOLOR = \033[0m
LGRAY = \033[1;30m
RED = \033[0;31m
PURP = \033[0;35m
GOLD = \033[38;5;136m

all: $(NAME)

$(NAME):
	@echo "$(NCOLOR)"
	@echo "____________________________________________________________"
	@echo "____________________________________________________________"
	@echo "             .-..                       .  .-.              "
	@echo "             | _|_              o      _|_ |                "
	@echo "            -|- |      .,-. .--..  .--. | -|-               "
	@echo "             |  |      |   )|  /|  |  | |  |                "
	@echo "             |   -'____| -' '    --'   - -'|                "
	@echo "_____________'_________|___________________'________________"
	@echo "                       '$(GOLD)   by altikka                "
	@echo "$(NCOLOR)"
	@make -C ./libft
	@mkdir $(OBJ_DIR)
	@echo "$(LGRAY)[ft_printf] $(PURP)Making object files..."
	@gcc -c $(FLGS) $(INCS) $(SRCS)
	@mv *.o $(OBJ_DIR)
	@echo "$(LGRAY)[ft_printf] $(PURP)Creating library libftprintf.a"
	@ar rcs $(NAME) $(OBJS)
	@echo "$(LGRAY)[ft_printf] $(PURP)Library created!"

clean:
	@make -C ./libft/ clean
	@echo "$(LGRAY)[ft_printf] $(RED)Cleaning object files..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C ./libft/ fclean
	@echo "$(LGRAY)[ft_printf] $(RED)Removing library..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re