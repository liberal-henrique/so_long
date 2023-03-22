/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:46:22 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/22 20:52:53 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	give_x_max(char **tab)
{
	int	max_x;

	max_x = 0;
	while (tab[0][max_x] != '\n' && tab[0][max_x])
		max_x++;
	return (max_x);
}

int	give_y_max(char **tab)
{
	int	max_y;

	max_y = 0;
	while (tab[max_y])
		max_y++;
	return (max_y);
}

char	**clone(char **tab)
{
	char	**new_arr;
	int		max_y;

	max_y = give_y_max(tab);
	new_arr = malloc(sizeof(char *) * (max_y + 1));
	if (!new_arr)
		return (NULL);
	max_y = -1;
	while (tab[++max_y])
		new_arr[max_y] = ft_strdup(tab[max_y]);
	return (new_arr);
}

int	ft_validate(char **tab, t_vars size)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	copy = clone(tab);
	flood_fill(copy, size, 13, 4);
	while (copy[i])
	{
		j = 0;
		while (copy[i][j] != '\n' && copy[i][j])
		{
			if (copy[i][j] == 'E' || copy[i][j] == 'C')
			{
				free_2d(copy, 0);
				free_2d(tab, 4);
			}
			j++;
		}
		i++;
	}
	return (0);
}
