/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 01:58:02 by ryishii           #+#    #+#             */
/*   Updated: 2021/03/25 02:23:09 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_put_s(t_args *args, va_list ap)
{
	int		width;
	int		putlen;
	char	*s;
	int		res;

	width = args->has_width ? args->width : 0;
	s = va_arg(ap, char*);
	if (!s)
		s = "(null)";
	putlen = ft_strlen(s);
	if (args->has_pre)
		putlen = (putlen > args->pre) ? args->pre : putlen;
	res = 0;
	while (width - putlen > 0 && !args->align_left)
	{
		res += ft_putchar(args->fill_zero ? '0' : ' ');
		width--;
	}
	res += ft_putstrl(s, putlen);
	while (width - putlen > 0 && args->align_left)
	{
		res += ft_putchar(' ');
		width--;
	}
	return (res);
}

int		ft_put_c(t_args *args, va_list ap)
{
	int		width;
	int		c;
	int		res;

	width = args->has_width ? args->width : 0;
	c = (args->c == '%') ? '%' : va_arg(ap, int);
	res = 0;
	while (width - 1 > 0 && !args->align_left)
	{
		res += ft_putchar(args->fill_zero ? '0' : ' ');
		width--;
	}
	res += ft_putchar(c);
	while (width - 1 > 0 && args->align_left)
	{
		res += ft_putchar(' ');
		width--;
	}
	return (res);
}
