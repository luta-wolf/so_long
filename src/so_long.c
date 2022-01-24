/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:23:01 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/25 01:01:36 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../include/so_long.h"
#include "so_long.h"

int print_map(int fd)
{
	int i;
	int	flag;
	char *line;

	i = 0;
	flag = 1;
	while (flag)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free(line);
			i++;
		}
		else
			flag = 0;
	}
	printf("В карте %d строк\n", i);
	return(i);
}


void	parsing(int argc, char **argv)
{
	char	**arr;
	check_argc(argc, argv);
	arr = get_line(argv);
	check_map_line_pe(arr);
	check_map_arg(arr);
	free_arr(arr);

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
