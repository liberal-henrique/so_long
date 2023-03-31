/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:26:38 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/31 12:29:50 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include"mlx/mlx.h"

enum e_entity {
	PLAYER,
	ENEMY,
	EVENT,
	OBJ,
};

typedef struct s_animation
{
	t_list		*frames;
	int			width;
	int			height;
	int			delay;
	int			_tmp_delay;
	int			current_frame_num;
	long int	last_updated;
	long int	frame_count;
	enum entity	entity;
}				t_animation;

typedef struct s_sprite {
	t_list	*animations;
	char	*name;
	char	*file_path;
	t_img	sprite_img;
	int		width;
	int		height;
	int		z_index;
}		t_sprite;

typedef struct sprite_slice {
	int		x;
	int		y;
	int		width;
	int		height;
}			t_sprite_slice;

/* Sprite */
t_sprite		new_sprite(char *name, char *file_path, t_win *win);
t_animation		*slice_sprite(t_sprite s, sprite_slice slice, \
int frames, int delay, enum e_entity e);
void			destroy_sprite(t_sprite s);

#endif
