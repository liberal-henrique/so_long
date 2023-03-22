/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:25:02 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/22 20:52:23 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**deal_rec(int fd, int counter_row, char **array_2d)
{
	char	*saucisse;

	saucisse = get_next_line(fd);
	if (counter_row > 0 && !saucisse)
		array_2d = malloc(sizeof(char *) * (counter_row + 1));
	else
		array_2d = deal_rec(fd, counter_row + 1, array_2d);
	if (array_2d)
		array_2d[counter_row] = saucisse;
	return (array_2d);
}

int	checker_ber(char *str, char *element)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	i = i - 4;
	if (str[i] != '.')
		return (1);
	while (str[i] == element[j])
	{
		if (!str[i] && !element[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	check_wall(char **arr, int i_max)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	i_max--;
	while (arr[0][length] != '\n' && arr[i_max][length] != '\n')
	{
		if (arr[0][length] != '1' || arr[i_max][length] != '1')
			return (1);
		length++;
	}
	length--;
	while (i <= i_max)
	{
		if (arr[i][0] != '1' || arr[i][length] != '1')
			return (1);
		i++;
	}
	return (0);
}

//eu nao faco a verificacao de que ha ao menos um collectable
void	check_maps_elements(char **arr, t_vars *v)
{
	v->cnt_collectable = 0;
	v->cnt_player = 0;
	v->cnt_exit = 0;
	v->i = 0;
	while (arr[v->i])
	{
		v->j = 0;
		while (arr[v->i][v->j] != '\n' && arr[v->i][v->j])
		{
			if (arr[v->i][v->j] != '1' && arr[v->i][v->j] != '0' &&
				arr[v->i][v->j] != 'P' && arr[v->i][v->j] != 'E' &&
				arr[v->i][v->j] != 'C')
				free_2d(arr, 1);
			if (arr[v->i][v->j] == 'P')
				v->cnt_player = v->cnt_player + 1;
			if (arr[v->i][v->j] == 'E')
				v->cnt_exit = v->cnt_exit + 1;
			v->j++;
		}
		v->i++;
	}
	if ((v->cnt_player != 1 || v->cnt_exit != 1) || check_wall(arr, v->i) == 1)
		free_2d(arr, 2);
}

void	flood_fill(char **tab, t_vars size, int x, int y)
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
	flood_fill(tab, size, x, y + 1);
	flood_fill(tab, size, x, y - 1);
	flood_fill(tab, size, x + 1, y);
	flood_fill(tab, size, x - 1, y);
}
