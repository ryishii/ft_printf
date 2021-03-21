/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 05:26:39 by ryishii           #+#    #+#             */
/*   Updated: 2020/11/27 02:08:18 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(long num, int fd)
{
	if (num / 10 == 0)
		ft_putchar_fd(num % 10 + '0', fd);
	else
	{
		putnbr(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	long num;

	num = (long)n;
	num = num < 0 ? -num : num;
	if (n < 0)
		write(fd, "-", 1);
	putnbr(num, fd);
}
