/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:22:03 by vkhut             #+#    #+#             */
/*   Updated: 2024/10/08 18:55:20 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	han_neg;

	han_neg = n;
	if (han_neg < 0)
	{
		ft_putchar_fd('-', fd);
		han_neg = -han_neg;
	}
	if (han_neg >= 10)
	{
		ft_putnbr_fd(han_neg / 10, fd);
	}
	ft_putchar_fd(han_neg % 10 + '0', fd);
}

// int main(void) {
//     int fd = 1; // Standard output file descriptor

//     // Test with various numbers
//     ft_putnbr_fd(12345, fd);
//     ft_putchar_fd('\n', fd); // Newline for better output readability

//     ft_putnbr_fd(-67890, fd);
//     ft_putchar_fd('\n', fd);

//     ft_putnbr_fd(-2147483648, fd); // Edge case for the minimum int
//     ft_putchar_fd('\n', fd);

//     ft_putnbr_fd(0, fd);
//     ft_putchar_fd('\n', fd);

//     return (0);
// }