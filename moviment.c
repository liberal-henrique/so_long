/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:48:10 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/22 15:23:07 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	img_right(t_vars *vars)
{
	//char	*image;

	//image = "./public/1.xpm";
	//counter_img = "./public/black1.xpm";
	clean_img(vars);
	vars->x++;
	start_img(vars);

	return (0);
}

int	img_left(t_vars *vars)
{
	//char	*image;

	//image = "./public/1.xpm";
	//counter_img = "./public/black1.xpm";
	clean_img(vars);
	vars->x--;
	start_img(vars);

	return (0);
}

int	img_up(t_vars *vars)
{
	//char	*image;

	//image = "./public/1.xpm";
	//counter_img = "./public/black1.xpm";
	clean_img(vars);
	vars->y--;
	start_img(vars);

	return (0);
}

int	img_down(t_vars *vars)
{
	//char	*image;
	//char	*counter_img;

	//image = "./public/1.xpm";
	//counter_img = "./public/black1.xpm";
	clean_img(vars);
	vars->y++;
	start_img(vars);

	return (0);
}
