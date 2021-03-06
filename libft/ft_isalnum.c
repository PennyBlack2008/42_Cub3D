/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:36:06 by jikang            #+#    #+#             */
/*   Updated: 2020/04/07 15:27:41 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int								ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
