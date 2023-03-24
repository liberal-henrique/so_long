/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:18:15 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/24 15:50:38 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	int		fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (checker_ber(av[1], ".ber") == 1)
		exit(write(1, "Error\n", 6));
	vars.map = deal_rec(fd, 0, NULL);
	check_maps_elements(vars.map, &vars);
	ft_validate(vars.map);
	window_init(&vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
