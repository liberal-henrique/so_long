/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:54:20 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/04 17:48:50 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_move(t_win *window)
{
	window->player.img[4] = load_image("public/pac_mouth_closed.xpm", \
	window->mlx_ptr);
	window->player.img[3] = load_image("public/pac_down.xpm", \
	window->mlx_ptr);
	window->player.img[2] = load_image("public/pac_up.xpm", \
	window->mlx_ptr);
	window->player.img[1] = load_image("public/pac_right.xpm", \
	window->mlx_ptr);
	window->player.img[0] = load_image("public/pac_left.xpm", \
	window->mlx_ptr);
}

void	images_counter_steps(t_win *window)
{
	window->steps[0] = load_image("public/num/zero.xpm", \
	window->mlx_ptr);
	window->steps[1] = load_image("public/num/um.xpm", \
	window->mlx_ptr);
	window->steps[2] = load_image("public/num/dois.xpm", \
	window->mlx_ptr);
	window->steps[3] = load_image("public/num/tres.xpm", \
	window->mlx_ptr);
	window->steps[4] = load_image("public/num/quatro.xpm", \
	window->mlx_ptr);
	window->steps[5] = load_image("public/num/cinco.xpm", \
	window->mlx_ptr);
	window->steps[6] = load_image("public/num/sies.xpm", \
	window->mlx_ptr);
	window->steps[7] = load_image("public/num/sete.xpm", \
	window->mlx_ptr);
	window->steps[8] = load_image("public/num/oito.xpm", \
	window->mlx_ptr);
	window->steps[9] = load_image("public/num/nove.xpm", \
	window->mlx_ptr);
}

void	images_ground(t_win *window)
{
	window->collect.img = load_image("public/collectable.xpm", \
	window->mlx_ptr);
	window->structure.wall = load_image("public/wall.xpm", window->mlx_ptr);
	window->structure.floor = load_image("public/black.xpm", window->mlx_ptr);
	window->structure.exit = load_image("public/door.xpm", window->mlx_ptr);
}

void	images_enemy(t_win	*window)
{
	window->enemy.img[0] = load_image("public/enemy_up.xpm", \
	window->mlx_ptr);
	window->enemy.img[1] = load_image("public/enemy_right.xpm", \
	window->mlx_ptr);
	window->enemy.img[2] = load_image("public/enemy_left.xpm", \
	window->mlx_ptr);
	window->enemy.img[3] = load_image("public/enemy_down.xpm", \
	window->mlx_ptr);
}

void	images_init(t_win *window)
{
	window->player.flag = 1;
	images_enemy(window);
	player_move(window);
	images_counter_steps(window);
	images_ground(window);
}
