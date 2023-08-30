# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjia <cjia@student.42tokyo.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 08:15:26 by yoshimurahi       #+#    #+#              #
#    Updated: 2023/08/30 15:42:36 by cjia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER_NAME = server
CLIENT_NAME = client
PRINTF_LIBFT = ft_printf/
SOURCE_C =	client.c
SOURCE_S =	server.c

CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJS_S = $(SOURCE_S:%.c=%.o)
OBJS_C = $(SOURCE_C:%.c=%.o)

all: $(NAME)

$(NAME) : $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(OBJS_C)
	make -C $(PRINTF_LIBFT)
	cp ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) $(OBJS_C) -o $(CLIENT_NAME) libftprintf.a
 
$(SERVER_NAME):$(OBJS_S)
	make -C $(PRINTF_LIBFT)
	cp ft_printf/libftprintf.a .
	$(CC) $(CFLAGS) $(OBJS_S) -o $(SERVER_NAME) libftprintf.a

clean:
	make clean -C $(PRINTF_LIBFT)
	rm -rf $(OBJS_C) $(OBJS_S)
	
fclean: clean
	make fclean -C $(PRINTF_LIBFT)
	rm -rf $(CLIENT_NAME) $(SERVER_NAME) libftprintf.a

re: fclean all 

.PHONY:	all clean fclean re
