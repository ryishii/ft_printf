/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:46:21 by ryishii           #+#    #+#             */
/*   Updated: 2021/03/25 01:28:15 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		slen;
	size_t		size;
	size_t		i;
	char		*res;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < (size_t)start)
		size = 0;
	else if (slen < (size_t)start + len)
		size = slen - (size_t)start;
	else
		size = len;
	if (!(res = malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}