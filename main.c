/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:18:15 by lliberal          #+#    #+#             */
/*   Updated: 2022/12/18 17:12:40 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

enum
{
	ON_DESTROY = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_D = 100,
	KEY_S = 115,
	KEY_ESTART = 101,
	KEY_ERASE = 102,
	KEY_SPACE = 32,
	KEY_PLUS = 65451,
	KEY_MINUS = 65453,
};

int	put_message(t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	start_img(t_vars *vars, char *image)
{
	char	*image_start;

	image_start = "./public/1.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, image_start, &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, vars->x, vars->y);
	return (0);
}

int	clean_img(t_vars *vars, char *image)
{
	char	*image_clean;

	image_clean = "./public/black1.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, image_clean, &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, vars->x, vars->y);
	return (0);
}

int	keypress(int keycode, t_vars *vars)
{
	static int	pos;

	printf("O valor da tecla: %i\n", keycode);
	if (keycode == ON_DESTROY)
		endgame(vars);
	if (keycode == KEY_SPACE)
		put_message(vars);
	if (keycode == KEY_D)
		img_right(vars);
	if (keycode == KEY_A)
		img_left(vars);
	if (keycode == KEY_W)
		img_up(vars);
	if (keycode == KEY_S)
		img_down(vars);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	char	*image;

	image = "./public/1.xpm";
	vars.x = 20;
	vars.y = 120;
	vars.mlx = mlx_init ();
	vars.img = mlx_new_image(vars.mlx, 80, 80);
	vars.mlx_win = mlx_new_window(vars.mlx, 640, 480, "Executing");


	mlx_hook(vars.mlx_win, 2, 1L << 0, keypress, &vars);
	mlx_loop(vars.mlx);
	return (0);
}


