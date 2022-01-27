/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parser_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:32:19 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/26 21:33:37 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_line(char **av)
{
	int		fd;
	char	*new_line;
	char	*line;
	char	*tmp;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_fd();
	new_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = new_line;
		new_line = ft_gnl_strjoin(new_line, line);
		free(tmp);
		free(line);
	}
	close(fd);
	return (new_line);
}

void	check_map_whole(t_map *map, char **av)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_fd();
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		i++;
		if (!line)
			break ;
		free(line);
	}
	if (i != map->width + 1)
		ft_error("В файле пустые строки.");
	close(fd);
}

void	check_map_line(t_map *map)
{
	int		i;
	int		j;
	char	*str;

	str = "01CEP";
	i = -1;
	while (map->map[++i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_strchr(str, map->map[i][j]))
				ft_error("Недопустимые символы в карте.");
			j++;
		}
		if (map->length != j)
			ft_error("Карта не прямоугольной формы.");
	}
}

void	check_map_arg(t_map *map)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = -1;
	while (map->map[++i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->koord.x = j;
				map->koord.y = i;
				// printf("x = %d, y = %d\n", j, i);
				player++;
			}
			else if (map->map[i][j] == 'C')
				map->coin++;
			j++;
		}
	}
	if (player != 1)
		ft_error("На карте должен быть один игрок.");
}

void	check_map_border(t_map *map, int i, int j)
{
	i = -1;
	while (map->map[0][++i])
	{
		if (map->map[0][i] != '1')
			ft_error("Карта разомкнута сверху.");
	}
	i = -1;
	while (map->map[map->width -1][++i])
	{
		if (map->map[map->width -1][i] != '1')
			ft_error("Карта разомкнута снизу.");
	}
	i = 0;
	while (map->map[++i] && i < map->width - 1)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][0] != '1')
				ft_error("Карта разомкнута слева.");
			else if (map->map[i][map->length - 1] != '1')
				ft_error("Карта разомкнута справа.");
		}
	}
}
