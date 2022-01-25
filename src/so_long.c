/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:23:01 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/25 23:15:25 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing(int argc, char **argv)
{
	t_map	*map;
	char	**arr;

	check_argc(argc, argv);
	arr = get_line(argv);
	map = init_map(arr);
	check_map_whole(map, argv);
	check_map_line(map);
	check_map_arg(map);
	check_map_border(map, 0, 0);
	free_arr_map(map, arr);
}

int	main(int argc, char **argv)
{
	parsing(argc, argv);
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
