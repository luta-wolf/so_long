/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parser_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:06:17 by einterdi          #+#    #+#             */
/*   Updated: 2022/01/25 13:00:15 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd("\033[31mError: \e[0m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_SUCCESS);
}

void	error_arg(char *str)
{
	ft_putstr_fd("\033[31mError: \e[0m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Example: ./so_long maps/1.ber\n", 2);
	exit(EXIT_SUCCESS);
}

void	check_argc(int ac, char **av)
{
	if (ac != 2)
		error_arg("Wrong number of arguments.");
	if(ft_strrchr(av[1], '/') && ft_strlen(ft_strrchr(av[1], '/')) == 5)
		error_arg("It is not a map.");
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		error_arg("Use files with 'ber' extension.");
}

void	error_fd(void)
{
	ft_putstr_fd("\033[31mError:\e[0m ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(".\n", 2);
	exit(EXIT_FAILURE);
}

void	free_arr_map(t_map *map, char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	free(map);
}
