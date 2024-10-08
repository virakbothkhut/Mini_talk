#ifndef MINITALK_H
# define MINITALK_H

#   include <stdio.h>
#   include <unistd.h>
#   include <stdlib.h>
#   include <stdarg.h> 
#   include <signal.h>
#   include "../Libft/libft.h"

int		ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

# define ERROR "\n\033[6;91mAchtung Achtung Achtung!\033[0m"
# define END_SER "\033[0;90mWRONG NUMBER.\033[0m\n"

#endif