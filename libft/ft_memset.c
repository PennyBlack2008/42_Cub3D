/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:58:50 by jikang            #+#    #+#             */
/*   Updated: 2020/04/07 15:17:46 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *s, int c, size_t n)
{
	unsigned char *str;

	str = (unsigned char *)s;
	while (n-- > 0)
	{
		*str = (unsigned char)c;
		str++;
	}
	return (s);
}
