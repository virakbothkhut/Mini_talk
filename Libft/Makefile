# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_atoi.c
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Rule to compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files
clean:
	rm -f $(OBJS)

# Clean all generated files (object files + library)
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all
