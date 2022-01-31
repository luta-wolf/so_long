/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parser_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 08:32:19 by einterdi          #+#    #+#             */
/*   Updated: 2022/02/01 00:50:44 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	str = "01CEPX";
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

void	init_player(t_map *map, int i, int j, int *player)
{
	map->play_coord.x = j;
	map->play_coord.y = i;
	*player += 1;
}

void	check_map_arg2(t_map *map, int i, int j)
{
	int	player;
	int	exit;

	player = 0;
	exit = 0;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
				init_player(map, i, j, &player);
			else if (map->map[i][j] == 'C')
				map->coin++;
			else if (map->map[i][j] == 'X')
				map->enemy++;
		}
	}
	if (player != 1)
		ft_error("На карте должен быть один игрок.");
	if (map->coin < 0)
		ft_error("На карте должены быть книги.");
	if (exit < 0)
		ft_error("На карте должен быть выход.");
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
