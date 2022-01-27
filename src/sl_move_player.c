/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:35:30 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/27 10:46:11 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keys(t_map *map, int key)
{
	if (key == UP)
		move_player_up(map);
	// else if (key == DOWN)
	// 	move_player_down(map);
	// else if (key == LEFT)
	// 	move_player_left(map);
	// else if (key == RIGHT)
	// 	move_player_right(map);
}

int	move_player_up(t_map *map)
{
	{
		if (map->map[map->koord.y][map->koord.x - 1] == '1')
			map->map[map->koord.y][map->koord.x] = map->map[map->koord.y][map->koord.x];
		else if (map->map[map->koord.y][map->koord.x -1] == '0')
		{
			map->map[map->koord.y][map->koord.x -1] = 'P';
			map->map[map->koord.y][map->koord.x] = '0';
		}
		else if (map->map[map->koord.y][map->koord.x -1] == 'C')
		{
			map->map[map->koord.y][map->koord.x -1] = 'P';
			map->map[map->koord.y][map->koord.x -1] = '0';
			map->coin--;
		}
		else if (map->map[map->koord.y][map->koord.x -1] == 'E')
		{
			if (map->coin == 0)
			{
				printf("Игра окончена.");
				exit(0);
			}
		}
	}
	map->steps++;
	map->koord.x--;
	ft_putnbr_fd(map->steps, 1);
	return (0);
}
