/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 00:40:43 by ryishii           #+#    #+#             */
/*   Updated: 2021/03/25 02:29:36 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_w(char const *s, char c)
{
	int		i;
	size_t	size;

	size = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			size++;
		i++;
	}
	return (size);
}

static void		*a_free(char **str, int j)
{
	int		i;

	i = 0;
	while (i != j)\
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len;
	char			**str;

	if (s == NULL || !(str = (char**)malloc(sizeof(char*) * count_w(s, c))))
		return (NULL);
	i = 0;
	j = 0;
	len = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			len = 0;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			if (!(str[j] = ft_substr(s, (unsigned int)(i + 1 - len), len)))
				return (a_free(str, j));
			j++;
		}
		i++;
		len++;
	}
	str[j] = NULL;
	return (str);
}
