/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:20:17 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/26 10:52:27 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h> // strerror()
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h> // strerror()

// sprites
# define WALL "../sprites/wall.xpm"
# define FLOOR "../sprites/floor.xpm"
# define PLAYER
# define EXIT
# define COIN

// keys
# define ESC	53
#define UP		13
#define DOWN	1
#define LEFT	0
#define RIGHT	2

// size sprite X Y
# define SPRITE_X	64
# define SPRITE_Y	64

typedef struct s_map
{
	char	**map;
	int		e;
	int		p;
	int		length;
	int		width;
}				t_map;

// sl_parser_check.c
void	check_map_whole(t_map *map, char **av);
void	check_map_line(t_map *map);
void	check_map_arg(t_map *map);
void	check_map_border(t_map *map, int i, int j);
char	*get_line(char **av);

// sl_parser_init.c
t_map	*init_map(char *line);

// sl_parser_error.c
void	ft_error(char *str);
void	error_arg(char *str);
void	check_argc(int ac, char **av);
void	error_fd(void);
void	free_arr_map(t_map *map);

#endif

/*
arr[y][x] = arr[y*width + x]
0   1   2   3   4   5
6   7   8   9   10  11
12  13  14  15  16  17
18  19  20  21  22  23
24  25  26  27  28  29
30  31  32  33  34  35*/
