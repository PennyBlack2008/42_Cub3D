/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:24:04 by jikang            #+#    #+#             */
/*   Updated: 2020/04/07 15:20:26 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t			i;

	i = 0;
	while (i < count)
	{
		if (((unsigned char *)buf1)[i] != ((unsigned char *)buf2)[i])
			return (((unsigned char *)buf1)[i] - ((unsigned char *)buf2)[i]);
		i++;
	}
	return (0);
}
