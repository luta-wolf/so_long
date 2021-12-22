/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 19:55:08 by einterdi          #+#    #+#             */
/*   Updated: 2021/12/20 16:34:09 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		i;
	int		rd;

	i = 0;
	line = (char *)malloc(1000);
	while ((rd = read(fd, line + i, 1)) > 0)
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	line[i] = '\0';
	return (line);
}
