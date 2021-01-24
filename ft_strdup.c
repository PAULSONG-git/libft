/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:58:56 by psong             #+#    #+#             */
/*   Updated: 2021/01/22 12:01:18 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i >= 0)
	{
		dest[i] = s1[i];
		i--;
	}
	return (dest);
}
