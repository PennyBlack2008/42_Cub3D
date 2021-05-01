/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:44:46 by jikang            #+#    #+#             */
/*   Updated: 2020/04/15 16:12:55 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_calloc(size_t num, size_t size)
{
	void					*new;

	if (!(new = (void *)malloc(size * num)))
		return (NULL);
	ft_memset(new, 0x00, num * size);
	return (new);
}
