/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:32:23 by psong             #+#    #+#             */
/*   Updated: 2021/01/21 16:39:47 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		finding(const char *str, const char *to_find, unsigned int i)
{
	unsigned int	k;
	unsigned int	j;

	k = 0;
	j = 0;
	while (to_find[j])
	{
		if (str[i] == to_find[j])
		{
			k++;
		}
		i++;
		j++;
	}
	if (k == j)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	z;

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
	return (0);
}
