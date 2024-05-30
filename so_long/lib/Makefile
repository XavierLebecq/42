# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 18:00:37 by xlebecq           #+#    #+#              #
#    Updated: 2024/05/30 13:50:54 by xlebecq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=clang
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
LDFLAGS=-L.
LDLIBS=-lft
SRC= 		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd_front.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstclear.c \
		ft_lstlast.c \
		ft_lstadd_back.c
		
SRC_PRINTF = 	ft_printf.c \
		ft_addfunctions.c
		
SRC_GNL = 	get_next_line.c \
		get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

OBJ_GNL = $(SRC_GNL:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I libft.h -c $< -o $@

$(NAME): $(OBJ) $(OBJ_PRINTF) $(OBJ_GNL)
	ar rc $(NAME) $(OBJ) $(OBJ_PRINTF) $(OBJ_GNL)
	ranlib $(NAME)

bonus : $(OBJB)
	ar rc $(NAME) $(OBJB)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ) $(OBJB) $(OBJ_PRINTF) $(OBJ_GNL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(SRCB)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(OBJB)
