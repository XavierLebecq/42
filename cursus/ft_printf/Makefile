# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 13:07:38 by xlebecq           #+#    #+#              #
#    Updated: 2024/01/21 13:32:58 by xlebecq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=clang
RM=rm -f
LIBFT= ./libft/ft_strdup.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c
SRC= ./src/ft_printf.c ./src/ft_addfunctions.c
OBJ= $(SRC:.c=.o)
OBJLIBFT= $(LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIBFT)
	ar rc $(NAME) $(OBJ) $(OBJLIBFT)
	ranlib $(NAME)

%.o: %.c
	$(CC) -I. -o $@ -c $? $(CFLAGS)

clean: 
	$(RM) $(OBJ) $(OBJLIBFT)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
