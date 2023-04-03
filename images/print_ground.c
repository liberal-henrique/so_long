/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ground.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:18:34 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/03 17:50:20 by lliberal         ###   ########.fr       */
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
			|| arr[comp.y][comp.x] == 'P' || arr[comp.y][comp.x] == 'F')
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
	window->canvas.img_ptr, 0, 0);
}

void	print_steps(t_win *window, int steps)
{
	t_img	*spaces[15];
	int		i;
	int		x;

	i = 14;
	spaces[i] = &window->steps[0];
	while (steps > 0)
	{
		spaces[i] = &window->steps[(steps % 10)];
		steps /= 10;
		if (steps > 0)
			i--;
	}
	x = 0;
	while (i < 15)
	{
		print_image(window->canvas, (96 + (32 * x)), window->canvas.h - 50, \
		*spaces[i++]);
		x++;
	}
}
