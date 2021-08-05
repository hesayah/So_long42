/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 00:24:49 by hesayah           #+#    #+#             */
/*   Updated: 2021/08/05 17:48:11 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include "libs/mlx/mlx.h"
# include "libs/libft/libft.h"
# include "libs/gnl/get_next_line.h"

typedef struct s_tex
{
	char			*r_path;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
	void			*img;
	int				*addr;
}					t_tex;

typedef struct s_draw
{
	int				x;
	int				y;
	int				r;
	int				g;
	int				b;
	float			scale_x;
	float			scale_y;
	unsigned long	color;
	int				pixel;
	float			pixel_x;
	float			pixel_y;
}					t_draw;

typedef struct s_game
{
	float			x;
	float			y;
	float			m_w;
	float			m_h;
	float			map_x;
	float			map_y;
	float			door_x;
	float			door_y;
	int				spown;
	int				collect;
	float			step;
	int				mob_x;
	int				mob_y;
	int				frame;
	char			*step_str;
}					t_game;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				w_w;
	int				w_max;
	int				w_h;
	int				h_max;
	int				err;
	char			**map;
	t_game			game;
	t_tex			tex[8];
	t_draw			draw;
}					t_data;

void			init_data(t_data *data);
int				pars_brain(char *file, t_data *data);
int				pars_map(t_data *data);
int				load_xpm(t_data *data);
int				render_next_frame(t_data *data);
void			move_mob(t_data *data);
void			draw_map(t_data *data);
void			my_mlx_pixel_put(int x, int y, int color, t_data *data);
int				action_key(int keycode, t_data *data);
int				clean_up(t_data *data);
int				close_window(t_data *data);

#endif
