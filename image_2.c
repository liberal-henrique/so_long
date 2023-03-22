/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:50:55 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/22 22:17:18 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_init(t_vars *vars)
{
	int	x_size;
	int	y_size;
	int	win_w;
	int	window_h;

	x_size = 80;
	y_size = 80;
	win_w = 580;
	window_h = 290;
	vars->mlx_ptr = mlx_init ();
	vars->img = mlx_new_image(vars->mlx_ptr, x_size, y_size);
	vars->mlx_win = mlx_new_window(vars->mlx_ptr, win_w, window_h, "so_long");
	mlx_hook(vars->mlx_win, 2, 1L << 0, keypress, vars);
}
