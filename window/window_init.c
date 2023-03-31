/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:42:50 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/31 17:57:45 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	window_init(t_win *window)
{
	window->mlx_ptr = mlx_init();
}

void	size_window(t_win *window)
{
	window->canvas.w = give_x_max(window->structure.map) * 32;
	window->canvas.h = give_y_max(window->structure.map) * 32;
}
