/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:33:49 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/28 10:39:32 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_img	canvas_init(t_win *mlx_ptr, int width, int height)
{
	t_img	canvas;

	canvas = new_image(width, height, mlx_ptr);
	return (canvas);
}
