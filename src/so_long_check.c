/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 21:29:43 by einterdi          #+#    #+#             */
/*   Updated: 2021/12/18 21:52:07 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void error_arg(char *str)
{
	ft_putstr_fd("\033[31mError: \e[0m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Example: ./so_long maps/1.ber\n", 2);
	exit(EXIT_SUCCESS);
}

void check_argc(int ac, char **av)
{
	if (ac != 2)
		error_arg("Wrong number of arguments.");
	if(ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		error_arg("It is not a map.");
}

void error_fd(void)
{
	ft_putstr_fd("\033[31mError:\e[0m ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(".\n", 2);
	exit(EXIT_FAILURE);
}
