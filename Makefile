# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: both <both@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 13:05:16 by vkhut             #+#    #+#              #
#    Updated: 2024/10/19 14:30:41 by both             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

CLIENT_FILES = client.c ft_atoi.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
SERVER_FILES = server.c ft_atoi.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f 

C_OBJ = $(CLIENT_FILES:.c=.o)
S_OBJ = $(SERVER_FILES:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(C_OBJ)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(C_OBJ)

$(NAME_SERVER): $(S_OBJ)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(S_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(C_OBJ) $(S_OBJ)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re

