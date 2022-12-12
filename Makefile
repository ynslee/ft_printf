# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 13:39:08 by yoonslee          #+#    #+#              #
#    Updated: 2022/12/12 14:38:15 by yoonslee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c ft_printf_ptr.c ft_printf_hex.c
OBJS = $(SRCS:.c = .o)
HEADER = ft_print.h
LIBFT_PATH = ./libft
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJS)
		$(make) -C $(LIBFT_PATH) all
		$(make) -C $(LIBFT_PATH) bonus
		cp $(LIBFT_PATH)$(LIBFT) .
		mv libft.a ./$(NAME)
		cc $(CFLAGS) $(SRCS) -I $(HEADER)
		ar -rus $(NAME) $(OBJS)

clean:
		make clean -C $(LIBFT_PATH)
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(LIBFT_PATH)$(LIBFT)
		rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re libft