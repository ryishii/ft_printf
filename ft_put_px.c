/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_px.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 23:15:55 by ryishii           #+#    #+#             */
/*   Updated: 2021/03/22 01:29:48 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     ft_get_digit_x(unsigned long ud)
{
    int     digit;

    digit = 0;
    while (ud / 16)
    {
        digit++;
        ud /= 16;
    }
    digit++;
    return (digit);
}

int     ft_putx(unsigned long ud, int padding, char c)
{
    int     res;

    res = 0;
    while (padding-- > 0)
        res += ft_putchar('0');
    if (ud / 16)
        res += ft_putx(ud / 16, padding, c);
    if (ud % 16 >= 10)
        res += ft_putchar((ud % 16) - 10 + c);
    else
        res+= ft_putchar(ud % 16 + '0');
    return (res);
}

int     ft_put_p(t_args *args, va_list ap)
{
    int             width;
    unsigned long   p;
    int             res;
    int             padding;

    res = 0;
    width = args->has_width ? args->width : 0;
    p = va_arg(ap, unsigned long);
    args->putlen = ft_get_digit_x(p) + 2;
    if (args->has_pre && args->pre == 0 && p == 0)
        args->putlen = 2;
    padding = (args->putlen < args->pre) ? args->pre - args->putlen + 2 : 0;
    args->putlen += padding;
    if (width - args->putlen > 0 && !args->align_left)
        res += align_right(width, args);
    res += ft_putstr("0x");
    if (!(args->has_pre && args->pre == 0 && p == 0))
        res += ft_putx(p, padding, 'a');
    if (width - args->putlen > 0 && args->align_left)
        res += align_left(width, args);
    return (res);
}

int     ft_put_x(t_args *args, va_list ap)
{
    int             width;
    unsigned long   d;
    int             padding;
    int             res;

    width = args->has_width ? args->width : 0;
    d = va_arg(ap, unsigned int);
    args->putlen = ft_get_digit_x(d);
    if (args->has_pre && args->pre == 0 && d == 0)
        args->putlen = 0;
    padding = (args->putlen < args->pre) ? args->pre - args->putlen : 0;
    args->putlen += padding;
    res = 0;
    if (width - args->putlen > 0 && !args->align_left)
        res += align_right(width, args);
    if (!(args->has_pre && args->pre == 0 && d == 0))
        res += ft_putx(d, padding, (args->c == 'x' ? 'a' : 'A'));
    if (width - args->putlen > 0 && args->align_left)
        res += align_left(width, args);
    return (res);
}