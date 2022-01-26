/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:23:01 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/26 21:18:14 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void game(t_map *map)
{
	// drow_image(map);
	drow_map(map);
}

t_map	*parsing(int argc, char **argv)
{
	t_map	*map;
	char	*line;

	check_argc(argc, argv);
	line = get_line(argv);
	map = init_map(line);
	init_sprites(map);
	check_map_whole(map, argv);
	check_map_line(map);
	check_map_arg(map);
	check_map_border(map, 0, 0);
	return (map);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = parsing(argc, argv);
	game(map);
	free_arr_map(map);
	return (0);
}

/*
План:
Построить линию
Проверить линию на
- Длину
- Символы
- Окруженность стенами
Потом сплит
Потом считаем высоту
И коллекции

*/
