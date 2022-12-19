/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:58:16 by lliberal          #+#    #+#             */
/*   Updated: 2022/12/18 17:13:37 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<stdlib.h>
# include<stdio.h>
# include"mlx/mlx.h"

# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD	2
# define MLX_SYNC_WIN_CMD_COMPLETE	3

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		img_width;
	int		img_height;
	int		endian;
	int		x;
	int		y;
}				t_vars;

int		keypress(int keycode, t_vars *vars);
int		put_message(t_vars *vars);
int		endgame(t_vars *vars);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int		start_img(t_vars *vars, char *image);
int		clean_img(t_vars *vars, char *image);
int		img_left(t_vars *vars);
int		img_right(t_vars *vars);
int		img_up(t_vars *vars);
int		img_down(t_vars *vars);
int		main(void);

#endif
