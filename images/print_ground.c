/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:18:34 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/29 12:54:32 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_ground(t_win *window, t_img canvas, char **arr)
{
	t_ground	comp;

	comp.y = -1;
	while (arr[++comp.y])
	{
		comp.x = -1;
		while (arr[comp.y][++comp.x] != '\n' && arr[comp.y][comp.x])
		{
			if (arr[comp.y][comp.x] == '0' || arr[comp.y][comp.x] == 'C' \
			|| arr[comp.y][comp.x] == 'P')
				print_image(window->canvas, comp.x * 32, comp.y * 32, \
				window->structure.floor);
			else if (arr[comp.y][comp.x] == '1')
				print_image(window->canvas, comp.x * 32, comp.y * 32, \
				window->structure.wall);
			else if (arr[comp.y][comp.x] == 'E')
				print_image(window->canvas, comp.x * 32, comp.y * 32, \
				window->structure.exit);
		}
	}
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, \
	canvas.img_ptr, 0, 0);
}
