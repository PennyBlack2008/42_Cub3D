/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:31:59 by jikang            #+#    #+#             */
/*   Updated: 2020/04/07 14:05:49 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** It compares s1 and s2 until index equals n.
*/

int							ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t					index;

	if (n == 0)
		return (0);
	index = 0;
	while (s1[index] && s2[index] && s1[index] == s2[index] && index < n - 1)
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
