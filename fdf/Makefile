# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 17:42:35 by gwaymar-          #+#    #+#              #
#    Updated: 2019/05/22 11:33:56 by gwaymar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

# SRCS files
SRCS_PATH := ./src
SRCS_FILES := fdf.c draw.c main.c reader.c error.c reader_fill.c colors.c map_params_fill.c \
							map_params_2.c start_window.c line_draw.c colors_add.c projects.c coords.c \
							mouse.c  clear_del.c
SRCS := $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

# OBJ files
OBJECTS_PATH := ./obj
OBJECTS_FILES := $(SRCS_FILES:.c=.o)
OBJECTS := $(addprefix $(OBJECTS_PATH)/, $(OBJECTS_FILES))

CC := gcc
CFLAGS := -g
#CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -lm

# miniLibX
MLX_PATH := ./minilibx
MLX_NAME := miniLibX
MLX_LIB := $(addprefix $(MLX_PATH)/,mlx.a)
MLX_INC := -I $(MLX_PATH)
MLX_LNK := -L $(MLX_PATH) -l mlx -framework OpenGL -framework AppKit

# libft
LIB_PATH := ./lib/libft
LIB_NAME := libft.a
LIB := $(addprefix $(LIB_PATH)/,libft.a)
LIB_INC := -I $(LIB_PATH)
LIB_LNK := -L $(LIB_PATH) -l ft

# include lib and minilibX
INCLUDES := $(MLX_INC) $(LIB_INC) -I./includes
HEADER := ./includes/fdf.h

# console colors
COLOR_RESET := \033[0m
COLOR_RED := \033[31m
COLOR_BLUE := \033[34m
COLOR_YELLOW := \033[33m
COLOR_GREEN := \033[32m


#	First target
all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	@echo "$(COLOR_RED) > $(COLOR_RESET)Compilation FDF ..."
	@echo "$(LIB_NAME)     [$(COLOR_YELLOW)Compiling...$(COLOR_RESET)]"
	@make -C $(LIB_PATH) > /dev/null
	@echo "\033[1A\033[K\033[1A"
	@echo "$(LIB_NAME)  [$(COLOR_GREEN)OK$(COLOR_RESET)]"
	@echo "$(MLX_NAME)     [$(COLOR_YELLOW)Compiling...$(COLOR_RESET)]"
	@make -C $(MLX_PATH) > /dev/null
	@echo "\033[1A\033[K\033[1A"
	@echo "\033[1A\033[K\033[1A"
	@echo "$(MLX_NAME) [$(COLOR_GREEN)OK$(COLOR_RESET)]"
	@echo "$(NAME)     [$(COLOR_YELLOW)Compiling...$(COLOR_RESET)]"
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_LNK) $(LIB_LNK) -o $(NAME) $(LDFLAGS)
	@echo "\033[1A\033[K\033[1A"
	@echo "$(NAME)      [$(COLOR_GREEN)OK$(COLOR_RESET)]"
	@echo "$(COLOR_RED) > $(COLOR_BLUE)Compilation is ended$(COLOR_RESET)"

#	Objects compilation
$(OBJECTS_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p $(OBJECTS_PATH) >/dev/null
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@eval ALREADY_OBJ=x

#	Removing objects
clean:
	@echo "removing  object files - ..."
	@make -C $(LIB_PATH) clean > /dev/null
	@make -C $(MLX_PATH) clean > /dev/null
	@rm -rf $(OBJECTS_PATH) > /dev/null
	@echo "\033[1A\033[K\033[1A"
	@echo "removing  object files - done"

#	Removing objects and exe
fclean: clean
	@echo "removing  $(NAME) - ..."
	@make -C $(LIB_PATH) fclean > /dev/null
	@rm -rf $(NAME) > /dev/null
	@echo "\033[1A\033[K\033[1A"
	@echo "removing  $(NAME) - done"

#	All removing then compiling
re: fclean all

# Some fun
coffee:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@echo "\033[24A"
	@echo "\033[J\033[1A"
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@echo "\033[24A"
	@echo "\033[J\033[1A"
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@echo "\033[24A"
	@echo "\033[J\033[1A"
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'

.PHONY: clean fclean re all coffee
