/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:32:07 by ryishii           #+#    #+#             */
/*   Updated: 2021/03/25 02:31:53 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char*)s;
	i = ft_strlen(str) + 1;
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
			return (&str[i]);
	}
	return (NULL);
}
