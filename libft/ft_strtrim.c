/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryishii <ryishii@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 02:34:53 by ryishii           #+#    #+#             */
/*   Updated: 2020/11/27 02:53:56 by ryishii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	size_t	len;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (ft_strchr(set, (int)s1[i]) != NULL)
		i++;
	start = i;
	i = ft_strlen(s1);
	while (ft_strchr(set, (int)s1[i]) != NULL)
		i--;
	if (i < (int)start)
		len = 0;
	else
		len = (size_t)(i - start + 1);
	res = ft_substr(s1, start, len);
	return (res);
}
