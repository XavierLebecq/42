# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 13:44:58 by xlebecq           #+#    #+#              #
#    Updated: 2024/05/29 18:08:06 by xlebecq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

RM = rm -f

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR), $(C_FILE))

C_FILE = so_long.c windows_manager.c

OBJ = $(SRC:.c=.o)

HEADER_DIR= ./header/

CFLAGS = -Wall -Wextra -Werror -g3

LIBFT_DIR = ./libft/

LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = ./minilibx-linux/

MLX_FLAG = -lX11 -lXext -Lm1x -L/usr/lib/X11

MLX = $(MLX_DIR)libmlx.a

INCLUDES = -I$(MLX_DIR) -I$(HEADER_DIR) -I$(LIBFT_DIR)

all: $(NAME)

libft2:
	make -C $(LIBFT_DIR)

mlx:
	make -C $(MLX_DIR) 

$(NAME): mlx libft2 $(OBJ)
	$(CC) $(OBJ) $(MLX) $(LIBFT) $(MLX_FLAG) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

