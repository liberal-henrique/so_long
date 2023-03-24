/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:50:55 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/24 16:58:29 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_start(t_vars *vars)
{
	vars->player = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./public/pac_player.xpm", &vars->img_width, &vars->img_height);
	vars->floor = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./public/black.xpm", &vars->img_width, &vars->img_height);
	vars->wall = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./public/wall.xpm", &vars->img_width, &vars->img_height);
	vars->collect = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./public/collectable.xpm", &vars->img_width, &vars->img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./public/door.xpm", &vars->img_width, &vars->img_height);
}

void	render(char **map, t_vars *vars, int x, int y)
{
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n' && map[y][x])
		{
			if (map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, \
				vars->floor, x * 32, y * 32);
			else if (map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, \
				vars->wall, x * 32, y * 32);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, \
				vars->collect, x * 32, y * 32);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, \
				vars->exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

int	player_mov(void *vars)
{
	t_vars	*aux;

	aux = (t_vars *)vars;
	render(aux->map, aux, -1, 0);
	mlx_put_image_to_window(aux->mlx_ptr, aux->mlx_win, \
	aux->player, aux->x * 32, aux->y * 32);
	return (0);
}

void	window_init(t_vars *vars)
{
	int	x_size;
	int	y_size;
	int	win_w;
	int	window_h;

	vars->x = 20;
	vars->y = 100;
	x_size = 80;
	y_size = 80;
	win_w = give_x_max(vars->map) * 32;
	window_h = give_y_max(vars->map) * 32;
	vars->mlx_ptr = mlx_init ();
	if (!vars->mlx_ptr)
	{
		free_2d(vars->map, 0);
		endgame(vars);
	}
	vars->img = mlx_new_image(vars->mlx_ptr, x_size, y_size);
	vars->mlx_win = mlx_new_window(vars->mlx_ptr, win_w, window_h, "so_long");
	img_start(vars);
	mlx_hook(vars->mlx_win, 2, 1L << 0, keypress, vars);
	mlx_loop_hook(vars->mlx_ptr, player_mov, vars);
}
