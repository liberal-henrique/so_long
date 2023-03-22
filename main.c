/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:18:15 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/22 21:41:34 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	char	**map;
	int		fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	vars.x = 20;
	vars.y = 120;
	if (checker_ber(av[1], ".ber") == 1)
		exit(write(1, "Error\n", 6));
	map = deal_rec(fd, 0, NULL);
	check_maps_elements(map, &vars);
	ft_validate(map, vars);
	window_init(&vars);
	//image_start(&vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
