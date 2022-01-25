/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parser_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 21:29:43 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/25 14:38:07 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_line(char **av)
{
	int		fd;
	char	*new_line;
	char	*line;
	char	*tmp;
	char	**arr;

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
	arr = ft_split(new_line, '\n');
	free(new_line);
	close(fd);
	return (arr);
}

t_map	*init_map(char **arr)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		return NULL;
	i = 0;
	while (arr[i])
		i++;
	map->map = arr;
	map->length = ft_strlen(arr[0]);
	map->width = i;
	map->e = 0;
	map->p = 0;
	printf("Длина = %d, Ширина = %d\n", map->length, map->width);
	return (map);
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
	int		i;
	int		j;

	i = -1;
	while (map->map[++i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				map->p++;
			else if (map->map[i][j] == 'E')
				map->e++;
			j++;
		}
	}
	if (map->p != 1)
		ft_error("На карте должен быть один игрок.");
	if (map->e != 1)
		ft_error("На карте должен быть один выход.");
}

void	check_map_border(t_map *map)
{
	int i;
	int j;

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


