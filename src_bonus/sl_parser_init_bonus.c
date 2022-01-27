/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parser_init_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:37:40 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/27 22:03:08 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*init_map(char *line)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = ft_split(line, '\n');
	i = 0;
	while (map->map[i])
		i++;
	map->length = ft_strlen(map->map[0]);
	map->width = i;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->length * SPRITE_X, \
							map->width * SPRITE_Y, "so_long");
	map->coin = 0;
	map->steps = 0;
	free(line);
	return (map);
}

void	init_sprites(t_map *map)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	map->img.wall = mlx_xpm_file_to_image(map->mlx, WALL, &x, &y);
	map->img.floor = mlx_xpm_file_to_image(map->mlx, FLOOR, &x, &y);
	map->img.player = mlx_xpm_file_to_image(map->mlx, PLAYER, &x, &y);
	map->img.exit = mlx_xpm_file_to_image(map->mlx, EXIT, &x, &y);
	map->img.coin1 = mlx_xpm_file_to_image(map->mlx, COIN1, &x, &y);
	map->img.coin2 = mlx_xpm_file_to_image(map->mlx, COIN2, &x, &y);
	map->img.fire1 = mlx_xpm_file_to_image(map->mlx, ENEMY1, &x, &y);
	map->img.fire2 = mlx_xpm_file_to_image(map->mlx, ENEMY2, &x, &y);
	if (!map->img.wall || !map->img.floor || !map->img.player
		|| !map->img.exit || !map->img.coin1 || !map->img.coin2
		|| !map->img.fire1 || !map->img.fire2)
	{
		printf("Не удалось открыть файл с картинкой.\n");
		exit(1);
	}
	map->img.coin = map->img.coin1;
	map->img.fire = map->img.fire1;
}