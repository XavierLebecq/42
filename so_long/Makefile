# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 13:44:58 by xlebecq           #+#    #+#              #
#    Updated: 2024/06/10 11:29:37 by xlebecq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

HEADER_DIR= ./header/

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR), $(C_FILES))

C_FILES = so_long.c windows_manager.c check_args.c get_map.c check_map.c display.c new_fonctions.c

OBJ = $(SRC:.c=.o)

LIB_DIR = ./lib/

LIB = $(LIB_DIR)lib.a

MLX_DIR = ./minilibx-linux/

MLX_FLAG = -lX11 -lXext -Lmlx -L/usr/lib/X11

MLX = $(MLX_DIR)libmlx.a

INCLUDES = -I$(LIB_DIR) -I$(MLX_DIR) -I$(HEADER_DIR)

all: $(NAME)

lib2:
	make -C $(LIB_DIR)

mlx:
	make -C $(MLX_DIR) 

$(NAME): mlx lib2 $(OBJ)
	$(CC) $(OBJ) $(MLX) $(LIB) $(MLX_FLAG) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

