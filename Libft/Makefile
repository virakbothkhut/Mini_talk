# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 13:05:16 by vkhut             #+#    #+#              #
#    Updated: 2024/10/07 13:06:03 by vkhut            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_putstr_fd.c \ ft_atoi.c \ ft_putchar_fd.c \ ft_putnbr_fd.c \ ft_putstr_fd.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

OBJS = $(SRCS:.c=.o)


all:			$(NAME)

$(NAME):		$(OBJS)
					ar rcs $(NAME) $(OBJS)

%.o: %.c 
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				rm -f $(OBJS)


fclean:clean
				rm -f $(NAME)

re:fclean all

