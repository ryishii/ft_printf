/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:48:41 by ryishii           #+#    #+#             */
/*   Updated: 2021/03/25 02:27:07 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_nb(long n, char *res)
{
	long	tmp;
	int		pow;
	int		i;

	if (n == 0)
		return ;
	if (n < 0)
		n *= -1;
	tmp = n;
	pow = 1;
	while (tmp /= 10)
		pow *= 10;
	i = 0;
	while (pow)
	{
		res[i] = n / pow + '0';
		n %= pow;
		pow /= 10;
		i++;
	}
	res[i] = '\0';
}

static void	set_minus(int n, char *res, size_t len)
{
	if (n <= -1)
	{
		ft_memmove(res + 1, res, len);
		res[0] = '-';
	}
	return ;
}

char		*ft_itoa(int n)
{
	char	*res;
	long	nb;
	size_t	len;

	nb = (long)n;
	len = 1;
	if (nb < 0)
	{
		len += 1;
		nb *= -1;
	}
	while (nb /= 10)
		len++;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	set_nb((long)n, res);
	set_minus(n, res, len);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
	}
	return (res);
}
