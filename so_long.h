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

typedef	struct		s_player
{
	int				m_x;
	int				m_y;
	int				max_y;
	int				max_x;

}					t_player;

typedef	struct		s_texture
{
	char			*r_path;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
	void			*img;
	int				*addr;
}					t_texture;

typedef	struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	unsigned long	color;
}					t_rgb;


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
	char			**tab;
	char			**map;
	t_player		player;
	t_texture		t[5];
	t_rgb			rgb;
}					t_data;

void				loop_hook(t_data *data);
int					close_window(t_data *data);
int					ft_check_arg(int argc, char *str);
int					brain(int argc, char **argv, t_data *data);
void				init_data(t_data *data);
void				pars_brain(char *file, t_data *data);
int					pars_value_line(t_data *data);
int					c_in_str(char c, char *s2);
void				get_res(char *str, t_data *data);
unsigned long		ft_rgb(int r, int g, int b);
void				ft_get_map(int index, t_data *data);
void				init_map_and_cam(t_data *data);
void				get_first_player_pos(t_data *data);
int					pars_sprite(t_data *data);
int					load_xpm(t_data *data);
int					action_key(int keycode, t_data *data);
int					render_next_frame(t_data *data);
void				ray_casting(double *buff, t_data *data);
void				my_mlx_pixel_put(int x, int y, int color, t_data *data);
void				code_err(int code);
void				exit_error(int code, t_data *data);
int					clean_up(t_data *data);

#endif
