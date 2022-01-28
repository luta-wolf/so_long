/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:35:30 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/28 13:13:39 by einterdi         ###   ########.fr       */
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
	int		i;
	int		j;
	char	*count_step;
	static int		k;

	k++;
	if (k > 20)
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
	if (key == UP)
		move_player_up(map);
	else if (key == DOWN)
		move_player_down(map);
	else if (key == LEFT)
		move_player_left(map);
	else if (key == RIGHT)
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

void	steps(t_map *map)
{
	map->steps++;
	printf("Steps: %d\n", map->steps);
}

// int	animation(t_map *map)
// {
// 	usleep(500000);
// 	if (map->img.coin == map->img.coin1)
// 		map->img.coin = map->img.coin2;
// 	else if (map->img.coin == map->img.coin2)
// 		map->img.coin = map->img.coin1;
// 	drow_map(map);
// 	return 0;
// }

// mlx_put_image_to_window(map->mlx, map->win, map->img.coin2, j * 64, i * 64);

	// mlx_clear_window(map->map, map->win);
