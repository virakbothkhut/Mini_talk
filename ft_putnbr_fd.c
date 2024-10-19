/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:22:03 by vkhut             #+#    #+#             */
/*   Updated: 2024/10/19 21:38:11 by vkhut            ###   ########.fr       */
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
