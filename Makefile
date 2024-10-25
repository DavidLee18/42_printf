CC := cc
CFLAGS := -Wall -Werror -Wextra
NAME := libftprintf.a

BUILD_DIR := build
SRC_DIR := src

SRCS := src/ft_printf.c src/vprint_fmt.c src/ft_utox.c src/vprint_hex.c \
		src/is_conv_spec.c src/free_fmt_arg.c src/uprint_pad.c \
		src/iprints_.c src/iprintf3.c
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# BONUS			:=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
# 					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
# 					ft_lstmap.c ft_lstnew.c ft_lstsize.c
# BONUS_OBJS		:= $(BONUS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS) libft.a
	@ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
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

# bonus:	$(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME).a $(OBJS) $(BONUS_OBJS)

.PNONY: all claen fclean re # bonus
