/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:50:55 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/03 18:03:41 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_img	new_image(int w, int h, void *mlx_ptr)
{
	t_img	image;

	image.w = w;
	image.h = h;
	image.img_ptr = mlx_new_image(mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp, \
	&image.line_len, &image.endian);
	return (image);
}

t_img	load_image(char *path, void *mlx_ptr)
{
	t_img	image;

	image.img_ptr = mlx_xpm_file_to_image(mlx_ptr, \
	path, &image.w, &image.h);
	if (!image.img_ptr)
		write(1, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp, \
	&image.line_len, &image.endian);
	return (image);
}

void	print_image(t_img canvas, int x, int y, t_img content)
{
	content.posi_y = -1;
	while (++content.posi_y < content.h)
	{
		content.posi_x = -1;
		while (++content.posi_x < content.w)
		{
			my_mlx_pixel_put(&canvas, content.posi_x + x, content.posi_y + y, \
			my_mlx_pixel_get(&content, content.posi_x, content.posi_y));
		}
	}
}
