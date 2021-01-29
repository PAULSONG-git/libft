/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:45:20 by psong             #+#    #+#             */
/*   Updated: 2021/01/26 15:16:30 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (dstsize < i)
	{
		while (src[j])
			j++;
		return (dstsize + j);
	}
	while (src[j] && dstsize > 0 && i < dstsize - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	while (src[j++])
		i++;
	return (i);
}
