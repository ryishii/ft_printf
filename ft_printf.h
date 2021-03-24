/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 01:17:28 by ryishii           #+#    #+#             */
/*   Updated: 2021/03/25 02:22:08 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_args
{
	int		c;
	int		width;
	int		has_width;
	int		pre;
	int		has_pre;
	int		fill_zero;
	int		align_left;
	int		putlen;
}					t_args;

int					align_right(int width, t_args *args);
int					align_left(int width, t_args *args);
int					ft_get_digit(int d);
int					ft_get_digit_x(unsigned long ud);
int					ft_get_digit_u(unsigned int d);
int					ft_putchar(char c);
int					ft_putstr(char *str);
int					ft_putstrl(char *str, int len);
int					ft_isspace(char c);
int					ft_puti(int d, int padding);
int					ft_putui(unsigned int ud, int padding);
int					ft_putx(unsigned long ud, int padding, char	c);
int					ft_put_d(t_args *args, va_list ap);
int					ft_put_s(t_args *args, va_list ap);
int					ft_put_x(t_args *args, va_list ap);
int					ft_put_p(t_args *args, va_list ap);
int					ft_put_u(t_args *args, va_list ap);
int					ft_put_c(t_args *args, va_list ap);
void				initialize_args(t_args *args);
char				*ft_get_flag(t_args *args, char *itr);
char				*read_args(t_args *args, char *itr, va_list ap, int *res);
int					ft_printf(const char *fmt, ...);

#endif
