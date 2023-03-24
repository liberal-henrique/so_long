/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:12:13 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/23 16:18:37 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	endgame(t_vars *vars)
{
	if (vars->mlx_win)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
		mlx_destroy_display(vars->mlx_ptr);
	}
	exit(0);
}

void	free_2d(char **array, int message)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	if (message == 0)
		write(1, "Hey!\n", 5);
	if (message == 1)
		exit(write(1, "Char Wrong\n", 11));
	if (message == 2)
		exit(write(1, "Elements wrong\n", 15));
	if (message == 3)
		exit(write(1, "Wall wrong\n", 11));
	if (message == 4)
		exit(write(1, "No path possible\n", 17));
}

