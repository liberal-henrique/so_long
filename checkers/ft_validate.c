/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:52:06 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/05 10:10:31 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_validate(char **tab)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = clone(tab);
	if (!copy)
		return (0);
	flood_fill(copy, 1, 1);
	while (copy[i])
	{
		j = 0;
		while (copy[i][j] && copy[i][j] != '\n')
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
	free_2d(copy, 0);
	return (0);
}
