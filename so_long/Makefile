# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 13:44:58 by xlebecq           #+#    #+#              #
#    Updated: 2024/06/12 00:56:04 by xlebecq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

HEADER_DIR= ./header/

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR), $(C_FILES))

C_FILES = main.c check_args.c get_map.c check_map.c new_fonctions.c display.c

OBJ = $(SRC:.c=.o)

OBJ_DIR = $(addprefix $(OBJ_PATH), $(OBJ))

LIB_DIR = ./lib/

LIB = $(LIB_DIR)lib.a

MLX_DIR = ./minilibx-linux/

MLX_FLAG = -lX11 -lXext -Lmlx -L/usr/lib/X11

MLX = $(MLX_DIR)libmlx.a

INCLUDES = -I$(LIB_DIR) -I$(MLX_DIR) -I$(HEADER_DIR)

OBJ_PATH = .obj/

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

lib2:
	@make -C $(LIB_DIR) --no-print-directory

mlx:
	@make -C $(MLX_DIR) --no-print-directory

$(NAME): mlx lib2 $(OBJ)
	@$(CC) $(OBJ) $(MLX) $(LIB) $(MLX_FLAG) -o $(NAME)
	@echo "${GREEN}Build successful!${RESET}"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@echo "${GREEN}Compiled $<${RESET}"

clean:
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory
	@$(MAKE) -C $(LIB_DIR) fclean --no-print-directory
	@$(RM) $(OBJ)
	@echo "${GREEN}Cleaned all object files.${RESET}"

fclean: clean
	@$(RM) $(NAME)
	@echo "${GREEN}Fully cleaned project.${RESET}"

re: fclean all

.PHONY: all clean fclean re

