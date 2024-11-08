NAME = libft.a

# Source files for libft (in the root directory)
LIBFT_CFILES = ft_atoi.c ft_memcpy.c ft_strjoin.c ft_bzero.c ft_calloc.c \
               ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
               ft_itoa.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c \
               ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
               ft_strchr.c ft_strdup.c ft_striteri.c ft_strlcat.c ft_strlcpy.c \
               ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
               ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_split.c

LIBFT_BCFILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
                ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
                ft_lstiter_bonus.c ft_lstclear_bonus.c

# Source files for printf (in the 'printf' directory)
PRINTF_DIR = printf/
PRINTF_CFILES = $(PRINTF_DIR)ft_helpers.c $(PRINTF_DIR)ft_printnumb.c \
                $(PRINTF_DIR)ft_printhex.c $(PRINTF_DIR)ft_printptr.c \
                $(PRINTF_DIR)ft_printf.c

# Object files for libft
LIBFT_OFILES = $(LIBFT_CFILES:.c=.o)
LIBFT_BOFILES = $(LIBFT_BCFILES:.c=.o)

# Object files for printf
PRINTF_OFILES = $(PRINTF_CFILES:.c=.o)

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -Iprintf

# Combine all object files
OFILES = $(LIBFT_OFILES) $(PRINTF_OFILES)
BOFILES = $(LIBFT_BOFILES) $(PRINTF_OFILES)

# Rules
all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

bonus: $(OFILES) $(BOFILES)
	ar rcs $(NAME) $(BOFILES)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(PRINTF_DIR)%.o: $(PRINTF_DIR)%.c $(PRINTF_DIR)ft_printf.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIBFT_OFILES) $(LIBFT_BOFILES) $(PRINTF_OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean a
