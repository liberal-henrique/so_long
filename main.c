/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:18:15 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/17 18:27:22 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_2d(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

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

//1 is message of error;
//0 is message of 0K;
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
		exit(write(1, "Error faltou o formato\n", 22));
	while (str[i] == element[j])
	{
		if (!str[i] && !element[j])
			return (0);
		i++;
		j++;
	}
	exit(write(1, "Error faltou o formato\n", 22));
}

int	check_wall(char **arr, int i_max)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	i_max--;
	while (arr[0][length] && arr[i_max][length])
	{
		if (arr[0][length] != '1' && arr[i_max][length] != '1')
			return (1);
		length++;
	}
	length--;
	while (i <= i_max)
	{
		if ((arr[i][0] != '1' || arr[i][length] != '1') \
		|| arr[i][length + 1] != '\0')
			return (1);
		i++;
	}
	return (0);
}

void	check_maps_elements(char **arr)
{
	t_map	map;

	map.cnt_player = 0;
	map.cnt_exit = 0;
	map.i = -1;
	while (arr[++map.i])
	{
		map.j = -1;
		while (arr[map.i][++map.j])
		{
			if (arr[map.i][map.j] != '1' && arr[map.i][map.j] != '0' && \
			arr[map.i][map.j] != 'P' && arr[map.i][map.j] != 'E' && \
			arr[map.i][map.j] != 'C')
				free_2d(arr);
			if (arr[map.i][map.j] == 'P')
				map.cnt_player++;
			if (arr[map.i][map.j] == 'E')
				map.cnt_exit++;
		}
		if (map.cnt_player != 1 || map.cnt_exit != 1)
			free_2d(arr);
	}
	if (check_wall(arr, map.i) == 1)
		free_2d(arr);
}

enum
{
	ON_DESTROY = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_D = 100,
	KEY_S = 115,
	KEY_ESTART = 101,
	KEY_ERASE = 102,
	KEY_SPACE = 32,
	KEY_PLUS = 65451,
	KEY_MINUS = 65453,
};

int	put_message(t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	start_img(t_vars *vars, char *image)
{
	char	*image_start;

	image_start = "./public/1.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx_ptr, \
	image_start, &vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, \
	vars->img, vars->x, vars->y);
	return (0);
}

int	clean_img(t_vars *vars, char *image)
{
	char	*image_clean;

	image_clean = "./public/black1.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx_ptr, image_clean, \
	&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, \
	vars->img, vars->x, vars->y);
	return (0);
}

int	keypress(int keycode, t_vars *vars)
{
	static int	pos;

	printf("O valor da tecla: %i\n", keycode);
	if (keycode == ON_DESTROY)
		endgame(vars);
	if (keycode == KEY_SPACE)
		put_message(vars);
	if (keycode == KEY_D)
		img_right(vars);
	if (keycode == KEY_A)
		img_left(vars);
	if (keycode == KEY_W)
		img_up(vars);
	if (keycode == KEY_S)
		img_down(vars);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	char	*image;

	image = "./public/1.xpm";
	vars.x = 20;
	vars.y = 120;
	vars.mlx_ptr = mlx_init ();
	vars.img = mlx_new_image(vars.mlx_ptr, 80, 80);
	vars.mlx_win = mlx_new_window(vars.mlx_ptr, 640, 480, "Executing");

	mlx_hook(vars.mlx_win, 2, 1L << 0, keypress, &vars);
	mlx_loop(vars.mlx_ptr);
	return (0);
}


