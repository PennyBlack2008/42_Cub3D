/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 00:22:44 by jikang            #+#    #+#             */
/*   Updated: 2020/04/09 16:51:20 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	if (!src && !dest)
		return (NULL);
	ptr1 = (unsigned char*)dest;
	ptr2 = (unsigned char*)src;
	i = 0;
	if (ptr2 < ptr1)
		while (++i <= len)
			ptr1[len - i] = ptr2[len - i];
	else
		while (len-- > 0)
			*(ptr1++) = *(ptr2++);
	return (dest);
}
