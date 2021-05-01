/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:30:12 by jikang            #+#    #+#             */
/*   Updated: 2020/04/16 15:44:13 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int					ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int					ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int							ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
