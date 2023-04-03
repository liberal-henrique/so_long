/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:18:15 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/03 17:49:32 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	return_img_player(t_win *window, int flag)
{
	static int	i;

	if (i >= 20 && i <= 40)
		flag = 4;
	if (i > 51)
		i = 0;
	i++;
	return (window->player.img[flag]);
}

t_img	return_img_enemy(t_win *window)
{
	static int	i;

	return (window->enemy.img[i]);
}

void	init_enemy(t_win *window)
{
	printf("Player: %i\n", (int)window->player.x);
	printf("Enemy: %i\n", (int)window->enemy.x);
	if ((int)window->player.x > (int)window->enemy.x)
	{
		printf("Direita\n");
		window->enemy.x += 0.02f;
	}
	else if ((int)window->player.x < (int)window->enemy.x)
	{
		window->enemy.x -= 0.02f;
	}
	else if ((int)window->player.y > (int)window->enemy.y && (int)window->player.x == (int)window->enemy.x)
	{
		window->enemy.y += 0.02f;
	}
	else if ((int)window->player.y < (int)window->enemy.y && (int)window->player.x == (int)window->enemy.x)
	{
		window->enemy.y -= 0.02f;
	}
	print_image(window->canvas, (int)(window->enemy.x * 32), \
	(int)(window->enemy.y * 32), return_img_enemy(window));
}

int	player_mov(void *window)
{
	t_win	*aux;

	aux = (t_win *)window;
	print_ground(aux, aux->canvas, aux->structure.map);
	print_collectables(aux, aux->canvas, aux->structure.map);
	print_image(aux->canvas, (int)(aux->player.x * 32), \
	(int)(aux->player.y * 32), return_img_player(aux, aux->player.flag));
	print_steps(aux, aux->player.steps);
	init_enemy(window);
	return (0);
}

	// mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, \
	// window->structure.ground.img_ptr, 0, 0);

void	set_enemy_initial_position(t_win *window)
{
	window->enemy.x = 100;
	window->enemy.y = 100;
}

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
	mlx_loop_hook(window.mlx_ptr, player_mov, &window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
