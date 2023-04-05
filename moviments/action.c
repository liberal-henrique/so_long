/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:10:26 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/05 10:12:25 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	action(void *window)
{
	t_win	*aux;

	aux = (t_win *)window;
	print_ground(aux, aux->canvas, aux->structure.map);
	print_collectables(aux, aux->structure.map);
	print_image(aux->canvas, (int)(aux->player.x * 32), \
	(int)(aux->player.y * 32), return_img_player(aux, aux->player.flag));
	print_steps(aux, aux->player.steps);
	if (aux->counter.cnt_enemies != 0)
		init_enemy(window);
	return (0);
}
