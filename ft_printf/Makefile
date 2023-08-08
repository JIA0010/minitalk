# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 14:33:05 by cjia              #+#    #+#              #
#    Updated: 2023/07/18 13:20:06 by cjia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/
SOURCE = ft_printf_p.c \
		 ft_printf_hex.c \
		 ft_printf_i.c \
		 ft_printf_u.c \
		 ft_printf.c \
		 ft_printf_c.c \
		 ft_printf_s.c \


CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS = $(SOURCE:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJS)
#	ranlib $(NAME)

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re
