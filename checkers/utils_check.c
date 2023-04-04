/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:46:22 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/04 13:10:59 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	new_arr[max_y] = 0;
	return (new_arr);
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
