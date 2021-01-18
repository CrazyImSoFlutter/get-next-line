/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:31:31 by hnoh              #+#    #+#             */
/*   Updated: 2021/01/18 11:38:29 by nogeun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!src || !dst)
		return (0);
	while (src[j] && j < dstsize - 1 && dstsize > 0)
	{
		dst[j] = src[j];
		j++;
	}
	if (dstsize - j > 0)
		dst[j] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		destln;
	size_t		srcln;

	srcln = ft_strlen(src);
	destln = ft_strlen(dst);
	j = destln;
	i = 0;
	if (destln < size - 1 && size > 0)
	{
		while (src[i] && destln + i < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = 0;
	}
	if (destln >= size)
		destln = size;
	return (destln + srcln);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;

	if (!s1 || !s2)
		return (0);
	if (!(s3 = (char*)malloc(sizeof(*s3) * (ft_strlen(s1) +
											ft_strlen(s2) + 1))))
		return (0);
	i = 0;
	while (*s1)
		s3[i++] = *s1++;
	while (*s2)
		s3[i++] = *s2++;
	s3[i] = 0;
	return (s3);
}

char		*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	len = ft_strlen(s) + 1;
	if ((str = malloc(len)))
	{
		ft_strlcpy(str, s, len);
		return (str);
	}
	return (NULL);
}
