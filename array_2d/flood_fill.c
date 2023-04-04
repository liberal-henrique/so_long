/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:55:26 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/04 12:45:29 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **tab, int x, int y)
{
	int	collectables;

	collectables = 0;
	if (tab[y][x] == '1' || tab[y][x] == 'P')
		return ;
	if (tab[y][x] == '0')
		tab[y][x] = 'P';
	if (tab[y][x] == 'C' && ++collectables)
		tab[y][x] = 'P';
	if (tab[y][x] == 'E')
		tab[y][x] = 'P';
	flood_fill(tab, x, y + 1);
	flood_fill(tab, x, y - 1);
	flood_fill(tab, x + 1, y);
	flood_fill(tab, x - 1, y);
}

