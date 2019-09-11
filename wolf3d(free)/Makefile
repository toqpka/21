# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwaymar- <gwaymar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 17:42:35 by gwaymar-          #+#    #+#              #
#    Updated: 2019/09/11 19:23:43 by gwaymar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := wolf3d

# SRCS files
SRCS_PATH := ./src
SRCS_FILES := main.c init_func.c
SRCS := $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

# OBJ files
OBJECTS_PATH := ./obj
OBJECTS_FILES := $(SRCS_FILES:.c=.o)
OBJECTS := $(addprefix $(OBJECTS_PATH)/, $(OBJECTS_FILES))

CC := gcc
CCFLAGS := -g
#CCFLAGS := -Wall -Wextra -Werror
LDFLAGS := -lm

# SDL2
SDL_PATH := ./sdl2/Frameworks
SDL_NAME := SDL2
SDL_INC := -I $(addprefix $(SDL_PATH)/,SDL2.framework/Versions/A/Headers)
SDL_LNK := -framework SDL2 -F $(SDL_PATH)
SDL_rpath := -rpath $(SDL_PATH)
SDL_IMAGE_INC := -I $(addprefix $(SDL_PATH)/,SDL2_image.framework/Versions/A/Headers/)
SDL_TTF_INC := -I $(addprefix $(SDL_PATH)/,SDL2_ttf.framework/Versions/A/Headers)
SDL_MIXER_INC := -I $(addprefix $(SDL_PATH)/,SDL2_mixer.framework/Versions/A/Headers)
SDL_IMAGE_LNK := -framework SDL2_image -F $(SDL_PATH)
SDL_TTF_LNK := -framework SDL2_ttf -F $(SDL_PATH)
SDL_MIXER_LNK := -framework SDL2_mixer -F $(SDL_PATH)
SDL2 := $(SDL_rpath) $(SDL_LNK) $(SDL_IMAGE_LNK) $(SDL_TTF_LNK) $(SDL_MIXER_LNK)

# libft
LIB_PATH := ./lib/libft
LIB_NAME := LibFT
LIB := $(addprefix $(LIB_PATH)/,libft.a)
LIB_INC := -I $(LIB_PATH)
LIB_LNK := -L $(LIB_PATH) -l ft

# include lib and minilibX
INCLUDES := $(LIB_INC) $(SDL_INC) $(SDL_IMAGE_INC) $(SDL_TTF_INC) $(SDL_MIXER_INC) -I ./includes
HEADER := ./includes/wolf3d.h ./includes/prototypes.h ./includes/structs.h

# console colors
COLOR_RESET := \033[0m
COLOR_RED := \033[31m
COLOR_BLUE := \033[34m
COLOR_YELLOW := \033[33m
COLOR_GREEN := \033[32m

#	First target
all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	@echo "$(COLOR_RED) > $(COLOR_RESET)Compilation $(NAME) $(COLOR_RED) < $(COLOR_RESET)"
	@echo "$(LIB_NAME)      [$(COLOR_YELLOW)Compiling...$(COLOR_RESET)]"
	@make -C $(LIB_PATH) > /dev/null
	@echo "\033[1A\033[K\033[1A"
	@echo "$(LIB_NAME)        [$(COLOR_GREEN)OK$(COLOR_RESET)]"
	@echo "$(NAME)     [$(COLOR_YELLOW)Compiling...$(COLOR_RESET)]"
	@$(CC) $(SDL2) $(CFLAGS) $(OBJECTS) $(LIB_LNK) -o $(NAME) $(LDFLAGS)
	@echo "\033[1A\033[K\033[1A"
	@echo "$(NAME)       [$(COLOR_GREEN)OK$(COLOR_RESET)]"
	@echo "$(COLOR_RED) > $(COLOR_BLUE)Compilation is ended$(COLOR_RESET)"

#	Objects compilation
$(OBJECTS_PATH)/%.o: $(SRCS_PATH)/%.c $(HEADER)
	@mkdir -p $(OBJECTS_PATH) >/dev/null
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#	Removing objects
clean:
	@echo "removing  object files - ..."
	@make -C $(LIB_PATH) clean > /dev/null
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

.PHONY: clean fclean re all
