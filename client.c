/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: both <both@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:36:34 by vkhut             #+#    #+#             */
/*   Updated: 2024/10/19 14:56:50 by both             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void cto_sig(int ser_pid, char c) {
    int c_bit = 0;

    while (c_bit < 8) {
        if (c & (1 << c_bit)) {
            kill(ser_pid, SIGUSR1); // Send 1
        } else {
            kill(ser_pid, SIGUSR2); // Send 0
        }
        usleep(100); // Small delay to allow for signal processing
        c_bit++;
    }
}

int main(int ac, char **av) {
    int ser_pid;
    int i = 0;

    if (ac != 3) {
        ft_putendl_fd("Usage: ./client <server_pid> <message>", 1);
        return (1);
    }

    ser_pid = ft_atoi(av[1]);
    if (ser_pid <= 1) {
        ft_putendl_fd("ERROR: Invalid server PID.", 1);
        return (1);
    }

    while (av[2][i]) {
        cto_sig(ser_pid, av[2][i]); // Send each character
        i++;
    }

    cto_sig(ser_pid, '\0'); // Send null character to indicate end of message

    return (0);
}

