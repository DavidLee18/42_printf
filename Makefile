CFLAGS := -Wall -Werror -Wextra -O2 -foptimize-sibling-calls
NAME := libftprintf.a

BUILD_DIR := build
SRC_DIR := src

SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c, build/%.o, $(SRCS))


all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS) libft.a
	@mv libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJS)

build/%.o: src/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(SRCS): libft/libft.h $(SRC_DIR)/ft_printf.h

libft.a:
	@make -C libft
	@cp libft/libft.a .

clean:
	rm -rf $(BUILD_DIR)
	make clean -C libft

fclean:	clean
	rm -f $(NAME)
	rm -f libft.a
	make fclean -C libft

re:	fclean $(NAME)

.PNONY: all clean fclean re bonus