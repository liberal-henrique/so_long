/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:58:16 by lliberal          #+#    #+#             */
/*   Updated: 2023/04/04 17:07:23 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include"mlx/mlx.h"

# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD	2
# define MLX_SYNC_WIN_CMD_COMPLETE	3

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

typedef struct s_list
{
	int				check_c;
	int				check_e;
}					t_list;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		h;
	int		w;
	int		posi_x;
	int		posi_y;
}			t_img;

typedef struct s_types_map
{
	int		cnt_player;
	int		cnt_exit;
	int		cnt_collectable;
	int		cnt_enemies;
}			t_types_map;

typedef struct s_ground
{
	char		**map;
	t_types_map	elements;
	t_img		wall;
	t_img		collect;
	t_img		floor;
	t_img		exit;
	t_img		ground;
	int			x;
	int			y;
}			t_ground;

typedef struct s_player
{
	double		x;
	double		y;
}			t_player;

typedef struct s_object
{
	t_img		img[6];
	int			flag;
	double		x;
	double		y;
	int			steps;
}			t_object;

typedef struct s_collect
{
	t_img		img;
	int			counter;

}				t_collect;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	char		*name;
	t_img		steps[10];
	t_img		canvas;
	t_ground	structure;
	t_object	player;
	t_object	enemy;
	t_collect	collect;
	t_types_map	counter;
}				t_win;

t_win			*so_long(void);

//-------------get_next_line------//
size_t			ft_strlen(char *s);
char			*ft_strchr(const char *str, int c);
char			*ft_substr(char const *s, unsigned int start, int len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(const char *s1);
char			*ft_read(int fd, char *buf, char *locker);
char			*ft_put_locked(char *line);
char			*get_next_line(int fd);

//-----------image 2----------//
t_img			new_image(int w, int h, void *mlx_ptr);
void			window_init(t_win *window);
void			size_window(t_win *window);
t_img			canvas_init(t_win *mlx_ptr, int width, int height);
int				my_mlx_pixel_get(t_img *data, int x, int y);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_img			new_image(int w, int h, void *mlx_ptr);
t_img			load_image(char *path, void *mlx_ptr);
void			print_image(t_img canvas, int x, int y, t_img	content);
void			playable_area(t_img canvas, char **matrix);
char			**deal_rec(int fd, int counter_row, char **array_2d);
int				checker_ber(char *str, char *element);
int				check_wall(char **arr, int i_max);
void			check_maps_elements(char **arr, t_ground s);
void			flood_fill(char **tab, int x, int y);
int				ft_validate(t_win *window, char **tab);
int				give_x_max(char **tab);
int				give_y_max(char **tab);
char			**clone(char **tab);
int				endgame(t_win *window);
void			free_2d(char **array, int message);
int				keypress(int keycode, t_win *position);
void			images_counter_steps(t_win *window);
void			images_init(t_win *window);
void			print_ground(t_win *window, t_img canvas, char **arr);
int				action(void *window);
void			put_floor_where_was_player(t_win *window);
void			put_player_in_the_new_position(t_win *window);
void			get_player_position(t_win *window);
void			get_enemy_position(t_win *win);
void			print_collectables(t_win *window, t_img canvas, char **arr);
void			print_steps(t_win *window, int steps);
void			set_enemy_initial_position(t_win *window);
t_img			return_img_player(t_win *window, int flag);
void			init_enemy(t_win *window);
int				colisions(t_win *window, t_object *obj, double x, double y);
#endif
