/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: both <both@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:11:31 by vkhut             #+#    #+#             */
/*   Updated: 2024/10/19 14:33:09 by both             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	sig_toc(int sig, siginfo_t *siginfo, void *contxt);
void	cto_sig(int ser_pid, char c);
int		ft_atoi(const char *str);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);


# define ERROR "\n\033[6;91mAchtung Achtung Achtung!\033[0m"
# define END_SER "\033[0;90mWRONG NUMBER.\033[0m\n"

#endif