# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 13:07:38 by xlebecq           #+#    #+#              #
#    Updated: 2023/12/31 15:17:18 by xlebecq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=clang
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
LIBFT= ./libft/
SRC= ./src/
OBJ= $(SRC: .c=.o)
OBJLIBFT= $(LIBFT: .c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIBFT)
	ar rc $(NAME) $(OBJ) $(OBJLIFT)
	ranlib $(NAME)

%.o: %.c
	$(CC) -I. -o $@ -c $? $(CFLAGS)

clean: $(RM) $(OBJ) $(OBJLibft)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
