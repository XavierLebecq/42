# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlebecq <xlebecq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 13:44:58 by xlebecq           #+#    #+#              #
#    Updated: 2024/06/24 23:04:22 by xlebecq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

HEADER_DIR= ./header/

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR), $(C_FILES))

C_FILES = main.c check_args.c get_map.c check_map.c utils.c display.c flood_fill.c player.c

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

# ---------------------------------------------------------------------
test:	lib2
	-@cc ./lib/test.c ./lib/lib.a -o ./lib/a.out
	$(call random_shmol_cat, teshting for Xavinou, , $(CLS), );
	@$(VALGRIND) lib/a.out





VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --track-fds=yes

CLEAR = \033[2J\033[H
CLS = \033[2J\033[H
RESET = \033[0m
BLINK = \033[5m
# U+2800 to U+28FF Braile
# <Esc>[38;5;ColorNumberm
BLACK = \033[38;5;0m
RED = \033[38;5;1m
GREEN = \033[38;5;2m
YELLOW = \033[38;5;3m
BLUE = \033[38;5;4m
MAGENTA = \033[38;5;5m
CYAN = \033[38;5;6m
GRAY = \033[38;5;7m

# big map, 3 pika
MAPG = good_map.ber
# big map, 3 pika
MAP1 = map1.ber
# big square, no pika
MAP2 = map2.ber
# medium square, lots of pika
MAP3 = map3.ber
# small square, 1 pika
MAP4 = map4.ber
# only balls
MAP5 = map5.ber

BAD_MAPS = map_bad_not_rect1.ber map_bad_not_rect2.ber map_no_collec.ber map_no_player.ber \
			map_no_exit.ber map_many_exit.ber \
			map_many_player.ber map_bad_wall.ber \
			map_bad_enclosed_e.ber map_bad_enclosed_c.ber \
			map_bad_tile.ber \

m: lib2 mlx $(NAME)
	@for map in $(BAD_MAPS); do \
	$(call random_shmol_cat, teshting lots of bad miaps:, $$map shouldt run..., $(CLS), ); \
	$(VALGRIND) ./$(NAME) map/map_bad/$$map; \
	echo "\t\033[5m~ Press Enter to continue...\033[0m"; \
	read -p "" key; \
	done
#
	$(call shmol_cat_color, $(COLOR_5R_0G_5B), $(COLOR_5R_2G_3B), teshing with bad map name!, map_multiplayer.be, $(CLS), )
	-$(VALGRIND) ./$(NAME) map/map_multiplayer.be
	@echo "\t\033[5m~ Press Enter to continue...\033[0m"
	@read -p "" key;
	@$(call shmol_cat_color, $(COLOR_5R_0G_5B), $(COLOR_5R_2G_3B), teshing with bad map name!, mapzzzzz.ber, $(CLS), )
	-$(VALGRIND) ./$(NAME) map/mapzzzzz.ber
	@echo "\t\033[5m~ Press Enter to continue...\033[0m"
	@read -p "" key
#
	@$(call random_shmol_cat, teshing too much args, "$(MAP1) abc", $(CLS), )
	-$(VALGRIND) ./$(NAME) map/$(MAP1) map/$(MAP2)
	@echo "\t\033[5m~ Press Enter to continue...\033[0m"
	@read -p "" key
#
	@$(call shmol_cat_color, $(COLOR_5R_0G_5B), $(COLOR_5R_2G_3B), teshing with empty file, map_blank.ber, $(CLS), )
	@echo "$(RED)"
	touch ./map/map_blank.ber
	@echo "$(COLOR_5R_0G_5B)"
	-$(VALGRIND) ./$(NAME) map/map_blank.ber
	@echo "\t\033[5m~ Press Enter to continue...\033[0m"
	@read -p "" key
#
	@$(call shmol_cat_color, $(COLOR_5R_4G_0B), $(COLOR_5R_2G_3B), teshing with a sprite file renamed!!!, , $(CLS), )
	@echo "$(RED)"
	mv ./sprites/player.xpm ./sprites/player_007.xpm
	@echo "$(COLOR_5R_4G_0B)"
	-$(VALGRIND) ./$(NAME) map/$(MAP1)
	@echo "$(RED)"
	mv ./sprites/player_007.xpm ./sprites/player.xpm
	@echo "\t\033[5m~ Press Enter to continue...\033[0m"
	@read -p "" key
#
	@$(call random_shmol_cat, "\'tis good map Mandatory", "try n break it.. にゃ?", $(CLS), )
	@echo "\t\033[5m~ Press Enter to continue...\033[0m"
	@read -p "" key
	-$(VALGRIND) ./$(NAME) map/$(MAP1)

# @$(call random_shmol_cat, text 1, text 2, $(CLS), $(RESET));
# $(1)= $(CLEAR); $(2)= text1; $(3)= text2; $(4)= $(RESET)
define random_shmol_cat
	COLOR=$$(printf "\033[38;5;%dm" $$(shuf -i 1-255 -n 1)); \
	COLOR2=$$(printf "\033[38;5;%dm" $$(shuf -i 0-255 -n 1)); \
	echo "$(3)$${COLOR2}\
	\tにゃ~$${COLOR}\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀$${COLOR2}~ $(1) ~$${COLOR}\n\
	\t\t⠀|、˜\\\\\t\t$${COLOR2}~ $(2)$${COLOR}\n\
	\t\t⠀じしˍ)ノ\n$(4)"
endef












