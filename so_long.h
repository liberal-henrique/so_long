/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:58:16 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/22 21:29:09 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include<stdlib.h>
# include<stdio.h>
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
}			t_img;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		bits_per_pixel;
	int		line_length;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		cnt_player;
	int		cnt_exit;
	int		cnt_collectable;
	int		movs;
	int		i;
	int		j;
	t_list	fill;
	void	*wall;
	void	*collect;
	void	*floor;
	void	*player;
	void	*exit;
}			t_vars;


//-------------checker----//
char		**deal_rec(int fd, int counter_row, char **array_2d);
int			checker_ber(char *str, char *element);
int			check_wall(char **arr, int i_max);
void		check_maps_elements(char **arr, t_vars	*map);
void		flood_fill(char **tab, t_vars size, int x, int y);

//-----------endgame------------//
int			endgame(t_vars *vars);
void		free_2d(char **array, int message);

//------------image--------------//
int			put_message(t_vars *vars);
void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int			start_img(t_vars *vars);
int			clean_img(t_vars *vars);
int			keypress(int keycode, t_vars *vars);
void		img_start(t_vars *vars);

//-----------image_2------------//
void		window_init(t_vars *vars);
int			ft_validate(char **tab, t_vars vars);
char		**clone(char **tab);

//--------------moviment--------//
int			img_left(t_vars *vars);
int			img_right(t_vars *vars);
int			img_up(t_vars *vars);
int			img_down(t_vars *vars);

//--------------split-----------//
char		write_word(char *dest, const char *from, char set);
int			word_count(const char *sr, char del);
void		add_split(char **dst, const char *string, char delimiter);
char		**ft_split(char const *s, char c);

//-------------get_next_line------//
size_t		ft_strlen(char *s);
char		*ft_strchr(const char *str, int c);
char		*ft_substr(char const *s, unsigned int start, int len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s1);
char		*ft_read(int fd, char *buf, char *locker);
char		*ft_put_locked(char *line);
char		*get_next_line(int fd);

#endif
