/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:35:30 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/27 18:53:20 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
