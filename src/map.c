/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:37:13 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/25 23:05:58 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define FLOOR "../sprites/floor.xpm"
#define WALL "../sprites/wall.xpm"
#define ESC 53
#define SPRITE_X 64
#define SPRITE_Y 64

typedef struct s_img
{
	void	*floor;
	void	*wall;
	int		sprite_x;
	int		sprite_y;
}			t_img;

typedef struct s_all
{
	void	*mlx;
	void	*win_mlx;
	int		width_win; // x
	int		heigth_win; // y
	t_img	img;
}			t_all;

int	keys(int key, t_all *all)
{
	if (key == ESC)
		exit(0);
	return (0);
}

int	end_game (t_all *all)
{
	printf("Thanks for your game\n");
	exit(0);
	return (0);
}

int	main(void)
{
	t_all	all;

	all.width_win = 13;
	all.heigth_win = 5;
	all.img.sprite_x = 64;
	all.img.sprite_y = 64;
	all.mlx = mlx_init();
	all.win_mlx = mlx_new_window(all.mlx, all.width_win * SPRITE_X, all.heigth_win * SPRITE_Y, "so_long");
	all.img.floor = mlx_xpm_file_to_image(all.mlx, FLOOR, &all.img.sprite_x, &all.img.sprite_y);
	all.img.wall = mlx_xpm_file_to_image(all.mlx, WALL, &all.img.sprite_x, &all.img.sprite_y);
	if (!all.img.floor)
	{
		printf("(1)\n");
		exit(0);
	}
	mlx_put_image_to_window(all.mlx, all.win_mlx, all.img.floor, 0 + 2 * 64, 0 + 4 * 64);
	mlx_put_image_to_window(all.mlx, all.win_mlx, all.img.wall, 0 + 0 * 64, 0 + 4 * 64);
	mlx_key_hook(all.win_mlx, keys, &all);
	mlx_hook(all.win_mlx, 17, 0, end_game, &all);
	mlx_loop(all.mlx);
}
