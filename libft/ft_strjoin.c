/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:30:34 by jikang            #+#    #+#             */
/*   Updated: 2020/05/28 13:17:11 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*ft_strjoin(char const *s1, char const *s2)
{
	char					*dest;
	size_t					len1;
	size_t					len2;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (!(dest = ft_calloc(len1 + len2 + 1, sizeof(char))))
			return (NULL);
		ft_memcpy(dest, s1, len1);
		ft_memcpy(dest + len1, s2, len2);
		dest[len1 + len2] = '\0';
		return (dest);
	}
	else
		return (NULL);
}
