# Variables
NAME = push_swap
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
CFILES = push_swap.c operations.c helpers.c
OFILES = $(CFILES:.c=.o)
CFLAGS = -I$(LIBFT_DIR) -I$(LIBFT_DIR)/printf

# Targets
all: $(NAME)

$(NAME): $(OFILES)
	cc $(OFILES) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
