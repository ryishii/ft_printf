/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 22:32:07 by ryishii           #+#    #+#             */
/*   Updated: 2020/11/27 01:47:14 by ryishii          ###   ########.fr       */
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
