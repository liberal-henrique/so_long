/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:32:06 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/22 22:17:30 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_message(t_vars *vars)
{
	(void) vars;
	printf("Hello from key_hook!\n");
	return (0);
}

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}



// void	array_with_images(char **arr, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (arr[i])
// 	{
// 		j = 0;
// 		while (arr[i][j])
// 		{
// 			if (arr[i][j] == '0')
// 			{

// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	img_start(t_vars *vars)
{
	vars->player = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./public/player.xpm", &vars->img_width, &vars->img_height);
	vars->floor = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./public/empty.xpm", &vars->img_width, &vars->img_height);
	vars->wall = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./public/wall.xpm", &vars->img_width, &vars->img_height);
	vars->collect = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./public/collectable.xpm", &vars->img_width, &vars->img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./public/exit.xpm", &vars->img_width, &vars->img_height);
}

int	start_img(t_vars *vars)
{
	char	*image_start;

	image_start = "./public/player_A_0.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx_ptr, \
	image_start, &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, \
	vars->img, vars->x, vars->y);
	return (0);
}

int	clean_img(t_vars *vars)
{
	char	*image_clean;

	image_clean = "./public/black1.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx_ptr, image_clean, \
	&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, \
	vars->img, vars->x, vars->y);
	return (0);
}

int	keypress(int keycode, t_vars *vars)
{
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
