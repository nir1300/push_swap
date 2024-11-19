# Define variables
NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Paths to libft and includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR) -I .

# Source files
SRC = push_swap.c operations.c helpers.c bidirectional.c 

OBJ = $(SRC:.c=.o)

# Compilation rules
all: $(LIBFT_BONUS) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
