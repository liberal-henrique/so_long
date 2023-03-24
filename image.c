/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:32:06 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/24 11:40:06 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_message(t_vars *vars)
{
	(void) vars;
	printf("Hello from key_hook!\n");
	return (0);
}

int	start_img(t_vars *vars)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx_ptr, \
	"./public/wall.xpm", &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, \
	vars->img, vars->x, vars->y);
	return (0);
}

int	clean_img(t_vars *vars)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx_ptr, "./public/black.xpm", \
	&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, \
	vars->img, vars->x, vars->y);
	return (0);
}
