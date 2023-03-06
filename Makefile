# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hachahbo <hachahbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 22:30:12 by hachahbo          #+#    #+#              #
#    Updated: 2022/12/30 13:26:29 by hachahbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus


SRCS = ft_printf.c ft_putchar.c \
		ft_putnbr.c ft_putstr.c \
		ft_puthex.c ft_putptr.c ft_atoi.c \

SRC_S = server.c \

SRC_S_BONUS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_puthex.c ft_putptr.c ft_atoi.c  

SRC_C = client.c \

SRC_C_BONUS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_puthex.c ft_putptr.c ft_atoi.c  

NAME = minitalk

OBJS = $(SRCS:.c=.o)

OBJS_C = $(SRC_C:.c=.o)
OBJ_C_BONUS = $(SRC_C_BONUS:.c=.o)
OBJS_S = $(SRC_S:.c=.o)
OBJS_S_BONUS = $(SRC_S_BONUS:.c=.o)

all: $(NAME)
	
$(NAME) : $(OBJS) $(OBJS_C) $(OBJS_S) minitalk.h
	cc -Wall -Wextra -Werror $(OBJS) $(OBJS_C) -o client	
	cc -Wall -Wextra -Werror $(OBJS) $(OBJS_S) -o server

bonus : $(OBJS) $(OBJS_C_BONUS) $(OBJS_S_BONUS) minitalk.h
	cc -Wall -Wextra -Werror  $(OBJS_S_BONUS) server_bonus.c  -o server_bonus
	cc -Wall -Wextra -Werror  $(OBJS_S_BONUS) client_bonus.c  -o client_bonus

%.o: %.c minitalk.h
	cc -Wall -Wextra -Werror -c $< -o $@ 

clean :
	rm -rf $(OBJS) $(OBJS_C) $(OBJS_S)

fclean : clean
	rm -rf $(NAME) $(CLIENT) $(SERVER) $(OBJS_S) $(OBJS_C) $(SERVER_BONUS) $(CLIENT_BONUS)

re : fclean all

.PHONY : re clean all flcean
