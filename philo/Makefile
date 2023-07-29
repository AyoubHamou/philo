# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 15:51:22 by ahamou            #+#    #+#              #
#    Updated: 2023/06/25 02:01:50 by ahamou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS =  -pthread -Wall -Werror -Wextra

SRCS = philo.c utils.c utils2.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean :
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re : fclean all

