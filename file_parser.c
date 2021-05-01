/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikang <jikang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:19:55 by jikang            #+#    #+#             */
/*   Updated: 2020/11/16 22:46:53 by jikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_handler(t_win *win, char *line, t_list **lst)
{
	if (win->map.info.nodouble_flag != 255)
		error_handler("map location in .cub!", 0);
	ft_lstadd_back(lst, ft_lstnew(ft_strdup(line)));
}

static void	parse_identifier(t_win *win, char *line, t_list **lst)
{
	if (*lst != NULL || *line)
	{
		if (ft_strncmp(line, "R ", 2) == 0)
			parse_resolution(win, line + 2, 'R');
		else if (ft_strncmp(line, "NO ", 3) == 0)
			parse_texture(win, line + 3, 'N');
		else if (ft_strncmp(line, "SO ", 3) == 0)
			parse_texture(win, line + 3, 'S');
		else if (ft_strncmp(line, "WE ", 3) == 0)
			parse_texture(win, line + 3, 'W');
		else if (ft_strncmp(line, "EA ", 3) == 0)
			parse_texture(win, line + 3, 'E');
		else if (ft_strncmp(line, "S ", 2) == 0)
			parse_texture(win, line + 2, 's');
		else if (ft_strncmp(line, "F ", 2) == 0)
			parse_color(win, line + 2, 'F');
		else if (ft_strncmp(line, "C ", 2) == 0)
			parse_color(win, line + 2, 'C');
		else if (*line == '\0' || *line == ' '
			|| *line == '0' || *line == '1' || *line == '2')
			map_handler(win, line, lst);
		else
			error_handler("Invalid char in map!", 0);
	}
}

static void	del(void *content)
{
	free(content);
}

void		check_file_extention(char *file, char *ext_name)
{
	char	*file_extention;

	file_extention = file + ft_strlen(file) - (ft_strlen(ext_name));
	if (ft_strlen(file_extention) != ft_strlen(ext_name))
		error_handler("extention error!", 0);
	if (ft_strncmp(file_extention, ext_name, ft_strlen(ext_name)) != 0)
		error_handler("extention error!", 0);
}

void		file_parser(t_win *win, char *file)
{
	char		*line;
	int			fd;
	t_list		*lst;
	int			ret;

	check_file_extention(file, ".cub");
	win->map.info.nodouble_flag = 0;
	lst = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		error_handler("Cannot open the file!", errno);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		parse_identifier(win, line, &lst);
		free(line);
		if (ret == 0)
			break ;
	}
	if (win->map.info.nodouble_flag != 255)
		error_handler("Key error!", 0);
	parse_map(win, lst);
	ft_lstclear(&lst, del);
	close(fd);
}
