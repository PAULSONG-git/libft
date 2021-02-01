/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:30:27 by paul              #+#    #+#             */
/*   Updated: 2021/01/31 21:09:26 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		finding(const char *str, const char *to_find, int i)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	while (to_find[j])
	{
		if (str[i] == to_find[j])
			k++;
		i++;
		j++;
	}
	if (k == j)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (!*to_find)
		return ((char *)&str[i]);
	while (str[i] && (size_t)i < len)
	{
		if (str[i] == to_find[0])
		{
			z = finding(str, to_find, i);
			if (z == 1 && (i + ft_strlen(to_find) <= len))
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
