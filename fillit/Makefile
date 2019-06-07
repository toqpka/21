# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/18 16:32:34 by jjory-ca          #+#    #+#              #
#    Updated: 2019/04/01 21:53:13 by gwaymar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit

SRC := fillit.c create_tabs.c cover_uncover.c \
				create_tetrim.c alg_x.c some_stuff.c move_topleft.c \
				matrix.c nodes.c links.c read_file.c ft_check_valid.c
INCL := -I./fillit.h
LIB_A := ./libft/libft.a
OBJ := $(SRC:.c=.o)
FLAG := -Wall -Werror -Wextra

all: $(NAME)

$(LIB_A):
	@make -C libft

%.o: %.c fillit.h
	@gcc $(FLAG) $(SRC) -I./libft $(INCL) -c $<

$(NAME): $(LIB_A) $(OBJ)
	@echo "===========[ \x1b[31mF \x1b[32mI \x1b[34mL \x1b[35mL \x1b[36mI \x1b[33mT \x1b[37m]==========="
	@echo ""
	@echo "\x1b[31m > \x1b[32mCompilation Fillit ...\x1b[37m"
	@gcc $(FLAG) -Llibft -lft $^ -o $@
	@echo "\x1b[31m > \x1b[34mCompilation is ended\x1b[37m"
	@echo ""
	@echo "====================================="

clean:
	@rm -f $(OBJ)
	@make -C libft clean > /dev/null

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re
