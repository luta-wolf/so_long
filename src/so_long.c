/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einterdi <einterdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:23:01 by einterdi          #+#    #+#             */
/*   Updated: 2021/12/20 16:23:43 by einterdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error_fd();
}

int	main(int argc, char **argv)
{
	check_argc(argc, argv);
	check_map(argv);
	return (0);
}
