# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 22:31:54 by xlebecq           #+#    #+#              #
#    Updated: 2024/10/10 18:28:39 by xlebecq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

HEADER_DIR= ./header/

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR), $(C_FILES))

C_FILES = main.c utils.c sort_operations.c sort.c push.c cost.c utils2.c push_sort.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft/

LIBFT = $(LIBFT_DIR)libft.a

INCLUDES = -I$(LIBFT_DIR) -I$(HEADER_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
		make -C $(LIBFT_DIR)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
