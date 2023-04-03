/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:06:50 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/03 16:35:55 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	colisions(t_win *window, t_object *obj, double x, double y)
{
	double	x1;
	double	y1;
	int		x2;
	int		y2;

	x1 = 0;
	y1 = 0;
	if (x >= 0)
		x1 = 0.5f;
	if (y >= 0)
		y1 = 0.5f;
	x += obj->x;
	y += obj->y;
	x2 = x1 + x;
	y2 = y1 + y;
	if ((int)window->structure.map[y2][x2] == '1')
		return (1);
	if ((int)window->structure.map[y2][x2] == 'C')
		window->structure.map[y2][x2] = '0';
	if (window->collect.counter == 0 && \
		(int)window->structure.map[y2][x2] == 'E')
		endgame(window);
	obj->x = x;
	obj->y = y;
	return (0);
}

int	flag_player_position(int keycode, t_win *position)
{
	if (keycode == KEY_D)
		position->player.flag = 1;
	else if (keycode == KEY_A)
		position->player.flag = 0;
	else if (keycode == KEY_W)
		position->player.flag = 2;
	else if (keycode == KEY_S)
		position->player.flag = 3;
}
// printf("O valor da tecla: %i\n", keycode);

int	keypress(int keycode, t_win *position)
{
	if (keycode == ON_DESTROY)
		endgame(position);
	flag_player_position(keycode, position);
	if (keycode == KEY_D)
	{
		if (colisions(position, &position->player, 0.5f, 0) == 0)
			position->player.steps += 1;
	}
	else if (keycode == KEY_A)
	{
		if (colisions(position, &position->player, -0.5f, 0) == 0)
			position->player.steps += 1;
	}
	else if (keycode == KEY_W)
	{
		if (colisions(position, &position->player, 0, -0.5f) == 0)
			position->player.steps += 1;
	}
	else if (keycode == KEY_S)
	{
		if (colisions(position, &position->player, 0, 0.5f) == 0)
			position->player.steps += 1;
	}
}
