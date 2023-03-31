/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_collectables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:05:10 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/30 15:53:44 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_collectables(t_win *window, t_img canvas, char **arr)
{
	t_ground	comp;

	comp.y = -1;
	window->collect.counter = 0;
	while (arr[++comp.y])
	{
		comp.x = -1;
		while (arr[comp.y][++comp.x] != '\n' && arr[comp.y][comp.x])
		{
			if (arr[comp.y][comp.x] == 'C')
			{
				print_image(window->canvas, comp.x * 32, comp.y * 32, \
				window->collect.img);
				window->collect.counter++;
			}

		}
	}
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, \
	canvas.img_ptr, 0, 0);
}
