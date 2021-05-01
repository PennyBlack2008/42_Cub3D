/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_part_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:27:41 by jikang            #+#    #+#             */
/*   Updated: 2020/11/16 22:51:51 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int					check_color(char **tmp)
{
	int	i;
	int j;
	int color;

	i = 0;
	while (tmp[i])
	{
		color = ft_atoi(tmp[i]);
		if (color < 0 || color > 255)
			return (0);
		j = 0;
		while (tmp[i][j])
		{
			if (ft_isdigit(tmp[i][j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	if (i < 3)
		return (0);
	return (1);
}

int					check_resol(char **tmp)
{
	int			i;
	int			j;

	i = 0;
	while (tmp[i] != 0)
		i++;
	if (i != 2)
		return (0);
	i = 0;
	j = 0;
	while (tmp[i] != 0)
	{
		j = 0;
		while (tmp[i][j] != 0)
		{
			if (!(ft_isdigit(tmp[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int					shut_down(t_win *w)
{
	exit(0);
}

int					prevent_double_flag(int bit_flag, t_win *win)
{
	unsigned char temp;

	if ((win->map.info.nodouble_flag & (1 << bit_flag)) == (1 << bit_flag))
		error_handler("double key error!", 0);
	win->map.info.nodouble_flag += (1 << bit_flag);
	return (1);
}
