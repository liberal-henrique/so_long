/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:58:24 by lliberal          #+#    #+#             */
/*   Updated: 2022/12/14 23:29:22 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include <stdio.h>
#include "mlx/mlx.h"

typedef struct	s_vars
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		img_width;
	int		img_height;
	int		endian;
}				t_vars;

// enum {
// 	ON_DESTROY = 65307,
// 	KEY_W = 0,
// };

// int	endGame(t_vars *vars)
// {
// 	(void)vars;
// 	exit(0);
// 	return (0);
// }

// int	keypress(int keycode, t_vars *vars)
// {
// 	static	int	pos;

// 	printf("O valor da tecla: %i\n", keycode);
// 	if (keycode == ON_DESTROY)
// 		endGame(vars);
// 	if (keycode == 32)
// 		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 15, 15);
// 	return (0);
// }

// int	next_frame(t_vars *vars)
// {
// 	static	int	i;

// 	printf("Executou %d\n", ++i);
// 	return (0);
// }

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_vars	vars;
	int i;
	int j;

	i = 0;
	j = 0;
	vars.mlx = mlx_init();
	vars.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Executing");
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
	// vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Hello World!");

	while (i < 1080/2)
	{
		j = 0;
		while (j < 1920/2)
		{
			my_mlx_pixel_put(&vars, j, i, 0x0000FF00);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 0, 0);
	mlx_loop(vars.mlx);
	return(0);
}













//gcc main.c -Lmlx -lmlx -L/usr/lib -lXext -lX11
// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx;
// 	vars.mlx_win;
// 	vars.mlx = mlx_init();
// 	vars.mlx_win = mlx_new_window(vars.mlx, 400, 400, "Hello World1");
// 	vars.img = mlx_xpm_file_to_image(vars.mlx_win, "1.xpm", &vars.img_width, &vars.img_height);
// 	mlx_hook(vars.mlx_win, 17, (1L<<2), endGame, &vars);
// 	mlx_hook(vars.mlx_win, 2, (1L<<0), keypress, &vars);


// 	mlx_loop_hook(vars.mlx, next_frame, &vars);

// 	mlx_loop(vars.mlx);
// 	return (0);
// }