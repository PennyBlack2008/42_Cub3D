/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:42:01 by jikang            #+#    #+#             */
/*   Updated: 2020/04/07 13:36:47 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void							*ft_memchr(const void *buf, int c, size_t count)
{
	size_t						i;

	i = 0;
	while (count--)
	{
		if (((unsigned char *)buf)[i] == (unsigned char)c)
			return (((void *)&((unsigned char *)buf)[i]));
		i++;
	}
	return (0);
}
