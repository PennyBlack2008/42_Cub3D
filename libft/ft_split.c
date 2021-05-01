/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:48:05 by jikang            #+#    #+#             */
/*   Updated: 2020/04/16 15:35:54 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_strnum(char const *s, char c)
{
	size_t			num;
	size_t			flag;
	size_t			i;

	num = 0;
	flag = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			num++;
		}
		i++;
	}
	return (num);
}

static size_t		ft_split_len(char const *s, char c, int i)
{
	size_t			length;

	length = 0;
	while (s[i] != c && s[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

static char			**freee(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char			**allocation(char const *s, char **dst, char c,\
		size_t str_num)
{
	size_t			i;
	size_t			j;
	size_t			unit_len;

	i = 0;
	j = 0;
	while (s[i] && j < str_num)
	{
		while (s[i] == c)
			i++;
		unit_len = ft_split_len(s, c, i);
		if (!(dst[j] = ft_calloc(unit_len + 1, sizeof(char))))
			return (freee((char const **)dst, j));
		ft_strlcpy(dst[j], s + i, unit_len + 1);
		j++;
		i += unit_len;
	}
	dst[j] = 0;
	return (dst);
}

char				**ft_split(char const *s, char c)
{
	char			**res;
	size_t			str_num;

	if (s == NULL)
		return (NULL);
	str_num = ft_strnum(s, c);
	if (!(res = (char **)ft_calloc(str_num + 1, sizeof(char *))))
		return (NULL);
	return (allocation(s, res, c, str_num));
}
