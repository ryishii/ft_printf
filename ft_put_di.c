/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:42:16 by ryishii           #+#    #+#             */
/*   Updated: 2021/03/25 01:28:15 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_puti(int d, int padding)
{
	int		res;

	res = 0;
	if (d == -2147483648)
	{
		res += ft_putchar('-');
		while (padding-- > 0)
			res += ft_putchar('0');
		res += ft_putstr("2147483648");
		return (res);
	}
	if (d < 0)
	{
		res += ft_putchar('-');
		d *= -1;
	}
	while (padding-- > 0)
		res += ft_putchar('0');
	if (d / 10)
		res += ft_puti(d / 10, padding);
	res += ft_putchar((d % 10) + '0');
	return (res);
}

void	ft_if_d_is_minus(int *padding, t_args *args, int *width)
{
	*padding = (args->putlen - 1) < args->pre ?
		args->pre - (args->putlen - 1) : 0;
	if (args->fill_zero && !args->has_pre)
	{
		*padding += *width - args->putlen;
		*width = 0;
	}
}

int		ft_put_d(t_args *args, va_list ap)
{
	int		width;
	long	d;
	int		padding;
	int		res;

	width = args->has_width ? args->width : 0;
	d = va_arg(ap, int);
	args->putlen = ft_get_digit(d);
	if (args->has_pre && args->pre == 0 && d == 0)
		args->putlen = 0;
	if (d < 0)
		ft_if_d_is_minus(&padding, args, &width);
	else
		padding = (args->putlen < args->pre) ? args->pre - (args->putlen) : 0;
	args->putlen += padding;
	res = 0;
	if (width - args->putlen > 0 && !args->align_left)
		res += align_right(width, args);
	if (!(args->has_pre && args->pre == 0 && d == 0))
		res += ft_puti(d, padding);
	if (width - args->putlen > 0 && args->align_left)
		res += align_left(width, args);
	return (res);
}