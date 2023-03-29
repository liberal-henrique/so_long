/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:56:21 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/28 12:56:42 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
