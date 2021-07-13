/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 00:24:49 by hesayah           #+#    #+#             */
/*   Updated: 2021/07/08 03:59:48 by hesayah          ###   ########.fr       */
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

typedef	struct		s_game
{
	int				x;
	int				y;
	int				m_w;
	int				m_h;
	float			map_x;
	float			map_y;
	int 			spown;
	int				collect;
}					t_game;


typedef struct		s_data
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
}					t_data;

int				pars_brain(char *file, t_data *data);
int				pars_map(t_data *data);
int					render_next_frame(t_data *data);
void				draw_map(t_data *data);
void			my_mlx_pixel_put(int x, int y, int color, t_data *data);
void			init_data(t_data *data);
int				action_key(int keycode, t_data *data);
int				clean_up(t_data *data);
int				close_window(t_data *data);

#endif
