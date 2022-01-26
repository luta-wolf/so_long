/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parser_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:37:40 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/26 11:01:26 by einterdi         ###   ########.fr       */
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
	map->e = 0;
	map->p = 0;
	free(line);
	return (map);
}
