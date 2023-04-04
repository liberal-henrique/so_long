/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:06:58 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/04 17:11:17 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_img	return_img_player(t_win *window, int flag)
{
	static int	i;

	if (i >= 20 && i <= 150)
		flag = 4;
	if (i > 250)
		i = 0;
	i++;
	return (window->player.img[flag]);
}

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

