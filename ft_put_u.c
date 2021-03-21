/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 23:16:50 by ryishii           #+#    #+#             */
/*   Updated: 2021/03/22 01:29:49 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int     ft_putui(unsigned int ud, int padding)
{
    int     res;

    res = 0;
    while (padding-- > 0)
        res += ft_putchar('0');
    if (ud / 10)
        res += ft_putui(ud / 10, padding);
    res += ft_putchar(ud % 10 + '0');
    return (res);
}

int     ft_put_u(t_args *args, va_list ap)
{
    int             width;
    unsigned int    ud;
    int             res;
    int             padding;

    width = args->has_width ? args->width : 0;
    ud = va_arg(ap, unsigned int);
    args->putlen = ft_get_digit_u(ud);
    if (args->has_pre && args->pre == 0 && ud == 0)
        args->putlen = 0;
    padding = (args->putlen < args->pre) ? args->pre - args->putlen : 0;
    args->putlen += padding;
    res = 0;
    if (width - args->putlen > 0 && !args->align_left)
        res += align_right(width, args);
    if (!(args->has_pre && args->pre == 0 && ud == 0))
        res += ft_putui(ud, padding);
    if (width - args->putlen > 0 && args->align_left)
        res += align_left(width, args);
    return (res);
}