# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoshimurahiro <yoshimurahiro@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 08:15:26 by yoshimurahi       #+#    #+#              #
#    Updated: 2023/08/05 11:57:03 by yoshimurahi      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
PRINTF_LIBFT = ft_printf/
SOURCE =	client.c \
			server.c \

CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS = $(SOURCE:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF_LIBFT)
	cp ft_printf/libftprintf.a .
	mv libftprintf.a $(NAME)
	ar rc $(NAME) $(OBJS)

clean:
	make clean -C $(PRINTF_LIBFT)
	rm -rf $(OBJS)
	
fclean: clean
	make fclean -C $(PRINTF_LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re
