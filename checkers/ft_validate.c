/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:52:06 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/28 12:58:06 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_validate(char **tab)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	copy = clone(tab);
	flood_fill(copy, 13, 4);
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
		break ;
	}
	return (0);
}
