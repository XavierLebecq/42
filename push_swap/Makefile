# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 22:31:54 by xlebecq           #+#    #+#              #
#    Updated: 2024/10/17 17:19:22 by xlebecq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

HEADER_DIR= ./header/

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR), $(C_FILES))

C_FILES = main.c utils.c stack_operations.c sort_stack.c push_execution_b.c push_execution_a.c costs_operations_a.c costs_operations_b.c position_utils.c node_utils.c stack_operations2.c sort_stack2.c

OBJ = $(C_FILES:.c=.o)

OBJS_DIR = objs/

OBJS = $(addprefix $(OBJS_DIR), $(OBJ))

LIBFT_DIR = ./libft/

LIBFT = $(LIBFT_DIR)libft.a

INCLUDES = -I$(LIBFT_DIR) -I$(HEADER_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
		make -C $(LIBFT_DIR)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
