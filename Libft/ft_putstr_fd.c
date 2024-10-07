/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:40:02 by vkhut             #+#    #+#             */
/*   Updated: 2024/10/07 11:40:03 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	while (*s)
	{
		write(fd, s++, 1);
	}
}

// #include <unistd.h> // For write function
// #include <stdio.h>  //

// int main(void)
// {
//     const char *message = "Hello, World!";

//     // Test with standard output (fd = 1)
//     ft_putstr_fd((char *)message, 1); // Should print: Hello, World!

//     // Test with standard error (fd = 2)
//     ft_putstr_fd((char *)message, 2); // Should print: Hello, World!

//     // Test with NULL string
//     ft_putstr_fd(NULL, 1); // This should do nothing without crashing

//     // Test with invalid file descriptor
//     ft_putstr_fd((char *)message, -1); // This should also do nothing

//     return (0);
// }