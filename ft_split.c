/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:42:44 by psong             #+#    #+#             */
/*   Updated: 2021/01/29 13:41:10 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_malloc_error(char **dst)
{
	unsigned int	i;

	i = 0;
	while (dst[i])
	{
		free(dst[i]);
		i++;
	}
	free(dst);
	return (NULL);
}

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	**ft_size_words(const char *s, char c, char **dst, int j)
{
	int	i;
	int	size_word;

	i = 0;
	while (s[i])
	{
		size_word = 0;
		if (s[i] != c)
		{
			while (s[i++] != c && s[i++])
				++size_word;
			dst[j++] = malloc(sizeof(char) * (size_word + 1));
			if (!dst)
				return (ft_malloc_error(dst));
		}
		else
			i++;
	}
	return (dst);
}

void		ft_do(const char *s, char **dst, char c, int i)
{
	int	k;
	int	j;

	j = 0;
	while (s[i])
	{
		k = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				dst[j][k++] = s[i++];
			dst[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	dst[j] = NULL;
}

char		**ft_split(const char *s, char c)
{
	char	**dst;

	if (!s)
		return (NULL);
	if (!(dst = malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (ft_malloc_error(dst));
	if (!(ft_size_words(s, c, dst, 0)))
		return (ft_malloc_error(dst));
	ft_do(s, dst, c, 0);
	return (dst);
}
