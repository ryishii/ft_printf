/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 22:00:47 by ryishii           #+#    #+#             */
/*   Updated: 2020/11/27 16:45:26 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	int i;

	i = 0;
	while (" \t\n\v\f\r"[i] != '\0')
	{
		if (" \t\n\v\f\r"[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		ft_ispm(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	return (0);
}

static size_t	atoi_strlen(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_ispm(str[i]) != 0)
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		len++;
		i++;
	}
	return (len);
}

static int		cmp_lmax(char *str, int sign, size_t i)
{
	long	n;
	size_t	tmp;

	n = 0;
	tmp = i;
	i += 1;
	if (atoi_strlen(str) > 19 && (sign == 1 || sign == 0)) 
		return (-1);
	else if (atoi_strlen(str) > 19 && sign == -1)
		return (0);
	else
	{
		while ('0' <= str[i] && str[i] <= '9')
		{
			n = n * 10 + str[i++] - '0';
			if (n > 223372036854775807 && (sign == 0 || sign == 1) 
					&& str[tmp] == '9')
				return (-1);
			else if (n > 223372036854775808 && sign == -1 
					&& str[tmp] == '9')
				return (0);
		}
	}
	return (1);
}


int				ft_atoi(const char *str)
{
	unsigned long	res;
	int				sign;
	size_t			i;

	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = ft_ispm(str[i]);
	if (sign != 0)
		i++;
	if (cmp_lmax((char*)str, sign, i) != 1)
		return (cmp_lmax((char*)str, sign, i));
	while ('0' <= str[i] && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (sign == 0)
		return ((int)res);
	return ((int)res * sign);
}
