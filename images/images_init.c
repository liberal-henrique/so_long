/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:54:20 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/29 19:48:02 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	images_init(t_win *window)
{
	window->player.img = load_image("public/pac_player.xpm", \
	window->mlx_ptr);
	window->structure.collect = load_image("public/collectable.xpm", \
	window->mlx_ptr);
	window->structure.wall = load_image("public/wall.xpm", window->mlx_ptr);
	window->structure.floor = load_image("public/empty.xpm", window->mlx_ptr);
	window->structure.exit = load_image("public/door.xpm", window->mlx_ptr);
}
