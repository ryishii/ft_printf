/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:46:21 by ryishii           #+#    #+#             */
/*   Updated: 2020/11/27 12:52:21 by ryishii          ###   ########.fr       */
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
