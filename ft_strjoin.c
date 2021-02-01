/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:03:42 by psong             #+#    #+#             */
/*   Updated: 2021/01/30 16:09:11 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 || !s2 ||
			!(dst = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_strlcpy(dst, s1, (ft_strlen(s1) + 1));
	ft_strlcat(dst, s2, len);
	return (dst);
}
