/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:47:53 by jikang            #+#    #+#             */
/*   Updated: 2020/04/27 19:03:03 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** https://www.ibm.com/support/knowledgecenter/ko/ssw_ibm_i_73/rtref/strdup.htm
*/

char						*ft_strdup(const char *str)
{
	size_t					len;
	char					*new;

	len = ft_strlen(str) + 1;
	if (!(new = (char *)malloc(sizeof(char) * len)))
		return (0);
	ft_memcpy(new, str, len);
	return (new);
}
