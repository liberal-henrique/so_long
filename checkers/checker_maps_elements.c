/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_maps_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:25:02 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/28 12:50:42 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_maps_elements(char **arr, t_ground s)
{
	s.elements.cnt_collectable = 0;
	s.elements.cnt_player = 0;
	s.elements.cnt_exit = 0;
	s.x = -1;
	while (arr[++s.x])
	{
		s.y = 0;
		while (arr[s.x][s.y] != '\n' && arr[s.x][s.y])
		{
			if (arr[s.x][s.y] != '1' && arr[s.x][s.y] != '0' &&
				arr[s.x][s.y] != 'P' && arr[s.x][s.y] != 'E' &&
				arr[s.x][s.y] != 'C')
				free_2d(arr, 1);
			if (arr[s.x][s.y] == 'P')
				s.elements.cnt_player = s.elements.cnt_player + 1;
			if (arr[s.x][s.y] == 'E')
				s.elements.cnt_exit = s.elements.cnt_exit + 1;
			s.y++;
		}
	}
	if ((s.elements.cnt_player != 1 || s.elements.cnt_exit != 1) \
	|| check_wall(arr, s.x) == 1)
		free_2d(arr, 2);
}
