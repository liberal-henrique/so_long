/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:58:16 by lliberal          #+#    #+#             */
/*   Updated: 2023/03/17 14:42:03 by lliberal         ###   ########.fr       */
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

typedef struct s_vars
{
	void	*mlx_ptr;
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
}			t_vars;

typedef struct s_img
{
	t_vars	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_map
{
	int		cnt_player;
	int		cnt_exit;
	int		cnt_collectable;
	int		i;
	int		j;
}			t_map;

int			keypress(int keycode, t_vars *vars);
int			put_message(t_vars *vars);
int			endgame(t_vars *vars);
void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int			start_img(t_vars *vars, char *image);
int			clean_img(t_vars *vars, char *image);
int			img_left(t_vars *vars);
int			img_right(t_vars *vars);
int			img_up(t_vars *vars);
int			img_down(t_vars *vars);
int			main(void);

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
