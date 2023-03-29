/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:06:50 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/29 20:02:22 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	colisions(t_win *window, t_object *obj, double x, double y)
{
	int	x1;
	int	y1;

	x1 = ((x >= 0) * 1.075f);
	y1 = ((y >= 0) * 1.075f);
	x += obj->x;
	y += obj->y;
	if ((int)window->structure.map[(int)y + y1][\
	(int)x + x1] == '1')
	{
		printf("hello\n");
		return ;
	}
	obj->x = x;
	obj->y = y;
}

int	keypress(int keycode, t_win *position)
{
	// printf("O valor da tecla: %i\n", keycode);
	if (keycode == ON_DESTROY)
		endgame(*position);
	// if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_W \
	// 	|| keycode == KEY_S)
	if (keycode == KEY_D)
		colisions(position, &position->player, 0.5f, 0);
	else if (keycode == KEY_A)
		colisions(position, &position->player, -0.5f, 0);
	else if (keycode == KEY_W)
		colisions(position, &position->player, 0, -0.5f);
	else if (keycode == KEY_S)
		colisions(position, &position->player, 0, 0.5f);
}
