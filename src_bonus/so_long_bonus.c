/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:23:01 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/28 15:45:29 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

	// mlx_key_hook(map->win, keys, map);
void	game(t_map *map)
{
	mlx_hook(map->win, 2, 0, keys, map);
	mlx_hook(map->win, 17, 0, end_game, map);
	mlx_loop_hook(map->mlx, drow_map, map);
	mlx_loop(map->mlx);
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
	check_map_arg(map, -1);
	check_map_border(map, 0, 0);
	init_enemy(map);
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
