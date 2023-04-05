/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:05:44 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/05 10:11:39 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_enemy_initial_position(t_win *window)
{
	window->enemy.x = 100;
	window->enemy.y = 100;
}

int	colisions_enemy(t_win *window, t_object *obj, double x, double y)
{
	x += obj->x;
	y += obj->y;
	if ((int)(x) == (int)window->player.x && (int)y == (int)window->player.y)
	{
		write(1, "You lose\n", 9);
		endgame(window);
	}
	obj->x = x;
	obj->y = y;
	return (0);
}

t_img	return_img_enemy(t_win *window, int flag)
{
	if (flag == 0)
	{
		if (colisions_enemy(window, &window->enemy, 0, -0.005f))
			window->enemy.y -= 0.001f;
		return (window->enemy.img[0]);
	}
	else if (flag == 1)
	{
		if (colisions_enemy(window, &window->enemy, 0.005f, 0))
			window->enemy.x += 0.001f;
		return (window->enemy.img[1]);
	}
	else if (flag == 2)
	{
		if (colisions_enemy(window, &window->enemy, -0.005f, 0))
			window->enemy.x -= 0.001f;
		return (window->enemy.img[2]);
	}
	else if (flag == 3)
	{
		if (colisions_enemy(window, &window->enemy, 0, 0.005f))
			window->enemy.y += 0.001f;
		return (window->enemy.img[3]);
	}
	return (window->enemy.img[0]);
}

void	init_enemy(t_win *window)
{
	int		flag;

	if ((int)window->player.x > (int)window->enemy.x)
		flag = 1;
	else if ((int)window->player.x < (int)window->enemy.x)
		flag = 2;
	else if ((int)window->player.y > \
	(int)window->enemy.y && (int)window->player.x == (int)window->enemy.x)
		flag = 3;
	else if ((int)window->player.y < \
	(int)window->enemy.y && (int)window->player.x == (int)window->enemy.x)
		flag = 0;
	print_image(window->canvas, (int)(window->enemy.x * 32), \
	(int)(window->enemy.y * 32), return_img_enemy(window, flag));
}

void	get_enemy_position(t_win *win)
{
	win->enemy.y = 0;
	win->counter.cnt_enemies = 0;
	while (win->structure.map[(int)win->enemy.y])
	{
		win->enemy.x = 0;
		while (win->structure.map[(int)win->enemy.y][(int)win->enemy.x] \
		!= '\n' && win->structure.map[(int)win->enemy.y][(int)win->enemy.x])
		{
			if (win->structure.map[(int)win->enemy.y][(int)win->enemy.x] \
			== 'F')
			{
				win->counter.cnt_enemies++;
				return ;
			}
			win->enemy.x++;
		}
		win->enemy.y++;
	}
	if (win->counter.cnt_enemies == 0)
		write(1, "No enemies\n", 11);
}
