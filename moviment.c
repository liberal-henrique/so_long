/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:48:10 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/23 15:49:11 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keycode, t_vars *vars)
{
	printf("O valor da tecla: %i\n", keycode);
	if (keycode == ON_DESTROY)
		endgame(vars);
	if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_W \
		|| keycode == KEY_S)
		clean_img(vars);
	if (keycode == KEY_D)
		vars->x = vars->x + 8;
	if (keycode == KEY_A)
		vars->x = vars->x - 8;
	if (keycode == KEY_W)
		vars->y = vars->y - 8;
	if (keycode == KEY_S)
		vars->y = vars->y + 8;
	return (start_img(vars));
}
