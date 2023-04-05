/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:18:15 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/05 10:09:52 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_win		window;
	int			fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (checker_ber(av[1], ".ber") == 1)
		exit(write(1, "Error\n", 6));
	window.structure.map = deal_rec(fd, 0, NULL);
	check_maps_elements(window.structure.map, window.structure);
	ft_validate(window.structure.map);
	size_window(&window);
	window_init(&window);
	window.canvas = canvas_init(window.mlx_ptr, \
	window.canvas.w, (window.canvas.h + 50));
	window.win_ptr = mlx_new_window(window.mlx_ptr, \
	window.canvas.w, window.canvas.h, "so_long");
	images_init(&window);
	get_player_position(&window);
	get_enemy_position(&window);
	mlx_hook(window.win_ptr, 2, 1L << 0, keypress, &window);
	mlx_hook(window.win_ptr, 17, 1L << 17, endgame, &window);
	mlx_loop_hook(window.mlx_ptr, action, &window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
