/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parser_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 21:29:43 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/25 00:41:25 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_line(char **av)
{
	int		fd;
	char	*new_line;
	char	*line;
	char	*tmp;
	char	**arr;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_fd();
	new_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = new_line;
		new_line = ft_gnl_strjoin(new_line, line);
		free(tmp);
		free(line);
	}
	arr = ft_split(new_line, '\n');
	check_map_arg(new_line);
	free(new_line);
	close(fd);
	return (arr);
}

void	check_map_arg(char *line)
{
	int		count_p;
	int		count_e;
	int		i;

	count_p = 0;
	count_e = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == 'P')
			count_p++;
		else if (line[i] == 'E')
			count_e++;
	}
	if (count_e > 1 || count_p > 1)
		ft_error("Карта не валидна. P или E > 1");
}

void	check_map_line(char **arr)
{
	int		i;
	int		j;
	int		n;
	char	*str;

	i = 0;
	n = 0;
	str = "01CEP";
	while (arr[0][i])
		i++;
	n = i;
	i = -1;
	while (arr[++i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (!ft_strchr(str, arr[i][j]))
				ft_error("Недопустимые символы в карте");
			j++;
		}
		if (n != j)
			ft_error("Карта не прямоугольной формы.");
	}
}
