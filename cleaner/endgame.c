/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:01:58 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/04 11:59:02 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_images(t_win *window)
{
	int	i;

	i = -1;
	while (++i < 5)
		mlx_destroy_image(window->mlx_ptr, window->player.img[i].img_ptr);
	i = -1;
	while (++i < 10)
		mlx_destroy_image(window->mlx_ptr, window->steps[i].img_ptr);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(window->mlx_ptr, window->enemy.img[i].img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->structure.wall.img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->structure.floor.img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->structure.exit.img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->collect.img.img_ptr);
	mlx_destroy_image(window->mlx_ptr, window->canvas.img_ptr);
}

int	endgame(t_win *window)
{
	if (window->win_ptr)
	{
		clean_images(window);
		free_2d(window->structure.map, 0);
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		mlx_destroy_display(window->mlx_ptr);
		free(window->mlx_ptr);
	}
	exit(0);
}

void	free_2d(char **array, int message)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	if (message == 0)
		write(1, "\n", 1);
	if (message == 1)
		exit(write(1, "Char Wrong\n", 11));
	if (message == 2)
		exit(write(1, "Elements wrong\n", 15));
	if (message == 3)
		exit(write(1, "Wall wrong\n", 11));
	if (message == 4)
		exit(write(1, "No path possible\n", 17));
}

