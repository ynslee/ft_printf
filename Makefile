
NAME = libftprintf.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CFlGAS = -Wall -Wextra -Werror

SOURCES = ./sources/ft_printf.c \
			./sources/ft_printf.c \
			./sources/ft_printf.c \

OBJECTS = $(SOURCES:.c = .o)

all:$(LIBFT) $(NAME)

$(LIBFT):
		make $(LIBFT_PATH)

$(NAME):$(OBJECTS)
			cp $(LIBFT) $(NAME)
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(LIBFT_PATH)
			ar rcs $(NAME) $(OBJECTS)

clean:
		make clean -C $(LIBFT_PATH)
		rm -f $(OBJECTS)

fclean:	clean
		make fclean -C $(LIBFT_PATH)
		rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re libft