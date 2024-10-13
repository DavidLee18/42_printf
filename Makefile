CC := cc
CFLAGS := -Wall -Werror -Wextra -g
NAME := libftprintf

BUILD_DIR := build
SRC_DIR := src

CS := ft_printf.c vprint_fmt.c
SRCS := $(SRC_DIR)/$(CS)
OBJS := $(BUILD_DIR)/$(CS:.c=.o)

# BONUS			:=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
# 					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
# 					ft_lstmap.c ft_lstnew.c ft_lstsize.c
# BONUS_OBJS		:= $(BONUS:.c=.o)


all: $(NAME) libft

$(NAME): $(OBJS)
	@ar -rcs $(NAME).a $(OBJS)

$(OBJS): $(SRCS)
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@make -C libft

clean:
	@rm -rf $(BUILD_DIR)

fclean:	clean
	@rm -f $(NAME).a

re:	fclean $(NAME)

# bonus:	$(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME).a $(OBJS) $(BONUS_OBJS)

.PNONY: all claen fclean re # bonus
