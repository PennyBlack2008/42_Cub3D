/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:26:54 by jikang            #+#    #+#             */
/*   Updated: 2020/11/17 00:25:57 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_width(t_list *lst)
{
	size_t	len;
	size_t	ret;
	size_t	i;

	len = 0;
	ret = 0;
	i = 0;
	while (lst)
	{
		len = ft_strlen(lst->content);
		if (len > ret)
			ret = len;
		lst = lst->next;
		i++;
	}
	return (ret);
}

void		parse_map(t_win *win, t_list *lst)
{
	int			i;

	win->map.map_height = ft_lstsize(lst);
	win->map.map = ft_calloc(win->map.map_height, sizeof(char *));
	win->map.map_width = get_map_width(lst);
	i = 0;
	while (i < win->map.map_height)
	{
		win->map.map[i] = malloc(win->map.map_width * sizeof(char));
		ft_memset(win->map.map[i], ' ', win->map.map_width);
		ft_memcpy(win->map.map[i], lst->content, ft_strlen(lst->content));
		lst = lst->next;
		i++;
	}
	map_validtator(win);
}

void		parse_color(t_win *win, char *line, char identifier)
{
	char	**tmp;
	t_color	*color;
	int		i;

	while (*line == ' ')
		line++;
	if (!(tmp = ft_split(line, ',')))
		error_handler("Memory allocation error!", ENOMEM);
	if (!check_color(tmp))
		error_handler("Color error in .cub file!", 0);
	if (identifier == 'F' && prevent_double_flag(1, win))
		color = &win->map.info.fl_rgb;
	else
	{
		prevent_double_flag(0, win);
		color = &win->map.info.cl_rgb;
	}
	color->trgb.r = ft_atoi(tmp[0]);
	color->trgb.g = ft_atoi(tmp[1]);
	color->trgb.b = ft_atoi(tmp[2]);
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void		parse_texture(t_win *win, char *line, char identifier)
{
	while (ft_isspace(*line))
		line++;
	if (identifier == 'N' && prevent_double_flag(6, win))
		win->map.info.no_texture = check_ext_xpm_and_strdup(line);
	else if (identifier == 'S' && prevent_double_flag(5, win))
		win->map.info.so_texture = check_ext_xpm_and_strdup(line);
	else if (identifier == 'W' && prevent_double_flag(4, win))
		win->map.info.we_texture = check_ext_xpm_and_strdup(line);
	else if (identifier == 'E' && prevent_double_flag(3, win))
		win->map.info.ea_texture = check_ext_xpm_and_strdup(line);
	else if (identifier == 's' && prevent_double_flag(2, win))
		win->map.info.sprite_texture = check_ext_xpm_and_strdup(line);
}

void		parse_resolution(t_win *win, char *line, char identifier)
{
	char	**tmp;
	int		i;

	if (!(tmp = ft_split(line, ' ')))
		error_handler("Memory allocation error!", ENOMEM);
	if (!check_resol(tmp))
		error_handler("Resolution error!", 0);
	if (identifier == 'R' && prevent_double_flag(7, win))
	{
		win->r_width = ft_atoi(line);
		while (ft_isspace(*line))
			line++;
		while (ft_isdigit(*line))
			line++;
		win->r_height = ft_atoi(line);
		if (win->r_width >= 1600)
			win->r_width = 1600;
		if (win->r_height >= 900)
			win->r_height = 900;
	}
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	resol_error(i, line);
}
