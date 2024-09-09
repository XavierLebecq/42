NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC =	operations/push.c \
		operations/reverse_rotate.c \
		operations/rotate.c \
		operations/swap.c \
		parsing/parsing_utils.c \
		parsing/parsing_utils2.c \
		parsing/parsing.c \
		utils/cheap.c \
		utils/cost.c \
		utils/find.c \
		utils/indice.c \
		utils/median.c \
		utils/stack_a.c \
		utils/stack_a_utils.c \
		utils/target.c \
		utils/total_cost.c \
		utils/utils_main.c \
		sort/middle_sort.c \
		sort/sort_gestion.c \
		sort/sort_stack.c \
		sort/sort_three.c \
		main.c 

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

all : $(LIBFT) $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

