/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:35:30 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/28 17:04:15 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drow_map2(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.wall, j * 64, i * 64);
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.floor, j * 64, i * 64);
	else if (map->map[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.player, j * 64, i * 64);
	else if (map->map[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.exit, j * 64, i * 64);
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.coin, j * 64, i * 64);
	else if (map->map[i][j] == 'X')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.fire, j * 64, i * 64);
}

void	animation(t_map *map)
{
	enemy_move(map);
	if (map->img.coin == map->img.coin1)
		map->img.coin = map->img.coin2;
	else if (map->img.coin == map->img.coin2)
		map->img.coin = map->img.coin1;
	if (map->img.fire == map->img.fire1)
		map->img.fire = map->img.fire2;
	else if (map->img.fire == map->img.fire2)
		map->img.fire = map->img.fire1;
}

int	drow_map(t_map *map)
{
	static int		k;
	int				i;
	int				j;
	char			*count_step;

	k++;
	if (k > 30)
	{
		animation(map);
		k = 0;
	}
	count_step = ft_itoa(map->steps);
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			drow_map2(map, i, j);
	}
	mlx_string_put(map->mlx, map->win, 10, 10, 0xff00, "Steps:");
	mlx_string_put(map->mlx, map->win, 75, 10, 0xff00, count_step);
	return (0);
}

int	keys(int key, t_map *map)
{
	if (key == UP || key == 126)
		move_player_up(map);
	else if (key == DOWN | key == 125)
		move_player_down(map);
	else if (key == LEFT | key == 123)
		move_player_left(map);
	else if (key == RIGHT | key == 124)
		move_player_right(map);
	else if (key == ESC)
		end_game();
	drow_map(map);
	return (0);
}

int	end_game(void)
{
	printf("Игра окончена.\n");
	exit(0);
	return (0);
}
	// mlx_clear_window(map->map, map->win);
