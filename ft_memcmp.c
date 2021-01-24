/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:34:48 by psong             #+#    #+#             */
/*   Updated: 2021/01/22 11:47:35 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (i < n && ((unsigned char*)s1)[i] == ((unsigned char*)s2)[i])
		i++;
	if (i == n)
		i--;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
