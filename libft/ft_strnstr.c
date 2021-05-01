/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:02:46 by jikang            #+#    #+#             */
/*   Updated: 2020/04/07 14:03:28 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		index;
	size_t		j;

	if (*little == '\0')
		return ((char *)big);
	index = 0;
	while (big[index] != '\0' && (size_t)index < len)
	{
		if (big[index] == little[0])
		{
			j = 1;
			while (little[j] != '\0' && big[index + j] == little[j] &&\
					(size_t)(index + j) < len)
				++j;
			if (little[j] == '\0')
				return ((char *)&big[index]);
		}
		index++;
	}
	return (0);
}
