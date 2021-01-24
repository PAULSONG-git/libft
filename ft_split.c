/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:42:44 by psong             #+#    #+#             */
/*   Updated: 2021/01/22 14:59:21 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(const char *s, char c)
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

char	**ft_size_words(const char *s, char c, char **dst)
{
	int	i;
	int	j;
	int	size_word;

	i = 0;
	j = 0;
	while (s[i])
	{
		size_word = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
			{
				++size_word;
				++i;
			}
			dst[j] = malloc(sizeof(char) * (size_word + 1));
			j++;
			if (!dst)
				return (NULL);
		}
		else
			i++;
	}
	return (dst);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**dst;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(dst = malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	if (!(ft_size_words(s, c, dst)))
		return (NULL);
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
	return (dst);
}
