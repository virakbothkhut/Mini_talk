/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: both <both@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:11:22 by vkhut             #+#    #+#             */
/*   Updated: 2024/10/19 15:43:07 by both             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_toc(int sig, siginfo_t *siginfo, void *contxt) {
    static int c_bit = 0;    // Bit index for the current character
    static char c_word = 0;  // Character being constructed

    (void)siginfo; // Not used
    (void)contxt;  // Not used

    if (sig == SIGUSR1) {
        c_word |= (1 << c_bit); // Set the bit for 1
    }
    c_bit++;

    if (c_bit == 8) { // Character complete
        ft_putchar_fd(c_word, 1);
        if (c_word == '\n') 
		{
			ft_putstr_fd("\n",1);
            ft_putstr_fd(END_SER, 1);
        }
        c_word = 0; 
        c_bit = 0;  
    }
}

int main(int ac, char **av) {
    struct sigaction ser_act;
    int pid;

    (void)av; // Ignore unused parameter
    if (ac != 1) {
        printf("ERROR: No arguments needed\n");
        return 1;
    }

    pid = getpid();
    printf("Server PID: %d\n", pid);

    ser_act.sa_sigaction = sig_toc;
    ser_act.sa_flags = SA_SIGINFO; 
    sigemptyset(&ser_act.sa_mask);


    sigaction(SIGUSR1, &ser_act, NULL);
    sigaction(SIGUSR2, &ser_act, NULL);

    while (1) { 
        pause(); 
    }

    return 0;
}


