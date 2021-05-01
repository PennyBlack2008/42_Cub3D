/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 23:01:29 by jikang            #+#    #+#             */
/*   Updated: 2020/04/07 13:54:04 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char						*ft_strrchr(const char *s, int c)
{
	char					*end_str;

	end_str = 0;
	while (*s)
	{
		if (*s == (char)c)
			end_str = (char *)s;
		s++;
	}
	if (end_str)
		return (end_str);
	if (c == '\0')
		return ((char *)s);
	return (0);
}
