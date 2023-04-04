/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:05:44 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/04 18:37:58 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_enemy_initial_position(t_win *window)
{
	window->enemy.x = 100;
	window->enemy.y = 100;
}

// int	test_colision(t_win *window, t_object *obj, double x, double y)
// {
// 	if (x2 == (int)window->player.x && y2 == (int)window->player.y)

// }

int	colisions_enemy(t_win *window, t_object *obj, double x, double y)
{
	double	x1;
	double	y1;
	int		x2;
	int		y2;

	x1 = 0;
	y1 = 0;
	if (x >= 0)
		x1 = 0.2f;
	if (y >= 0)
		y1 = 0.2f;
	x += obj->x;
	y += obj->y;
	x2 = x1 + x;
	y2 = y1 + y;
	printf("Enemy: %i\n", y2);
	printf("Enemy: %i\n", x2);
	printf("Player: %f\n", window->player.x);
	printf("Player: %f\n", window->player.y);
	if (x2 == (int)window->player.x && y2 == (int)window->player.y)
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
		if (colisions_enemy(window, &window->enemy, 0, -0.01f))
			window->enemy.y -= 0.001f;
		return (window->enemy.img[0]);
	}
	else if (flag == 1)
	{
		if (colisions_enemy(window, &window->enemy, 0.01f, 0))
			window->enemy.x += 0.001f;
		return (window->enemy.img[1]);
	}
	else if (flag == 2)
	{
		if (colisions_enemy(window, &window->enemy, -0.01f, 0))
			window->enemy.x -= 0.001f;
		return (window->enemy.img[2]);
	}
	else if (flag == 3)
	{
		if (colisions_enemy(window, &window->enemy, 0, 0.01f))
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
