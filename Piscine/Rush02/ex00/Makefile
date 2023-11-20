NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(shell find . -type f -name '*.c' -print)
HEADERS = $(shell find . -type f -name '*.h' -print)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o "$(NAME)"

all: $(NAME)

clean:
	@rm -f rush-02
