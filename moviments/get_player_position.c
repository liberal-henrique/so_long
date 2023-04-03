/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:26:44 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/03 17:12:20 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_player_position(t_win *win)
{
	win->player.y = 0;
	win->player.steps = 0;
	while (win->structure.map[(int)win->player.y])
	{
		win->player.x = 0;
		while (win->structure.map[(int)win->player.y][(int)win->player.x] \
		!= '\n' && win->structure.map[(int)win->player.y][(int)win->player.x])
		{
			if (win->structure.map[(int)win->player.y][(int)win->player.x] \
			== 'P')
				return ;
			win->player.x++;
		}
		win->player.y++;
	}
}

void	get_enemy_position(t_win *win)
{
	win->enemy.y = 0;
	while (win->structure.map[(int)win->enemy.y])
	{
		win->enemy.x = 0;
		while (win->structure.map[(int)win->enemy.y][(int)win->enemy.x] \
		!= '\n' && win->structure.map[(int)win->enemy.y][(int)win->enemy.x])
		{
			if (win->structure.map[(int)win->enemy.y][(int)win->enemy.x] \
			== 'F')
				return ;
			win->enemy.x++;
		}
		win->enemy.y++;
	}
}
