/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:32:23 by psong             #+#    #+#             */
/*   Updated: 2021/01/26 20:03:07 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	finding(const char *str, const char *to_find, size_t i)
{
	size_t	k;
	size_t	j;

	k = 0;
	j = 0;
	while (to_find[j++])
	{
		if (str[i] == to_find[j])
			k++;
		i++;
	}
	if (k == j)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!to_find)
		return ((char *)&str[i]);
	while (str[i] && i < len)
	{
		if (str[i] == to_find[0])
		{
			j = finding(str, to_find, i);
			if (j == 1 && (i + ft_strlen(to_find) <= len))
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
