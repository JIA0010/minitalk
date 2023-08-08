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





			
# NAME = libftprintf.a

# NAME_C = client
# NAME_S = server

# LIBFT = libft/ft_printf/libft.a

# SOURCE_C = client.c
# SOURCE_S = server.c 

# CC = cc
# CFLAGS = -Wall -Werror -Wextra
# OBJS_C = $(SOURCE_C:%.c=%.o)
# OBJS_S = $(SOURCE_S:%.c=%.o)

# all: $(NAME_C) $(NAME_S)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(LIBFT):
# 	make -C libft/ft_printf

# $(NAME_C): $(OBJS_C) $(LIBFT)
# 	$(CC) $(CFLAGS) -o $@ $(OBJS_C) -Llibft/ft_printf -lft
	
# $(NAME_S): $(OBJS_S) $(LIBFT)
# 	$(CC) $(CFLAGS) -o $@ $(OBJS_S) -Llibft/ft_printf -lft
	
# clean:
# 	make clean -C libft/ft_printf
# 	rm -rf $(OBJS_C) $(OBJS_S)

# fclean: clean
# 	rm -rf $(NAME_C) $(NAME_S) $(LIBFT)

# re: fclean all

# .PHONY:	all clean fclean re
