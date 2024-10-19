/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:11:22 by vkhut             #+#    #+#             */
/*   Updated: 2024/10/19 21:38:00 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_toc(int sig, siginfo_t *siginfo, void *contxt)
{
	static int	c_bit = 0;
	static int	c_word = 0;

	(void)siginfo;
	(void)contxt;
	if (sig == SIGUSR1)
	{
		c_word |= (1 << c_bit);
	}
	c_bit++;
	if (c_bit == 8)
	{
		ft_putchar_fd(c_word, 1);
		if (c_word == '\n')
		{
			ft_putstr_fd("\n", 1);
		}
		c_word = 0;
		c_bit = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	ser_act;
	int					pid;

	(void)av;
	if (ac != 1)
	{
		printf("ERROR: No arguments required\n");
		return (1);
	}
	pid = getpid();
	printf("Our Server PID is: %d\n", pid);
	ser_act.sa_sigaction = sig_toc;
	ser_act.sa_flags = SA_SIGINFO;
	sigemptyset(&ser_act.sa_mask);
	sigaction(SIGUSR1, &ser_act, NULL);
	sigaction(SIGUSR2, &ser_act, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
