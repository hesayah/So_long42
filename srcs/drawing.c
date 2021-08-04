/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:19:15 by hesayah           #+#    #+#             */
/*   Updated: 2021/08/02 23:38:03 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	scale(t_data *data, int index)
{
	//if (data->tex[index].img_width > data->game.m_w)
	data->draw.scale_x = ((float)data->tex[index].img_width
			/ data->game.m_w);
	/*else
		*scale_x = (data->game.m_w / (float)data->tex[index].img_width);*/
	//if (data->tex[index].img_height > data->game.m_h)
	data->draw.scale_y = ((float)data->tex[index].img_height
			/ data->game.m_h);
	/*else
		*scale_y = (data->game.m_h / (float)data->tex[index].img_height);*/
}


static	void	draw_square(t_data *data, float pos_x, float pos_y, int index)
{
	int		y;
	int		x;
	float	pixel_x;
	float	pixel_y;

	scale(data, index);
	y = (data->game.m_h * pos_y) + 1;
	pixel_y = 0;
	while (y > (data->game.m_h * pos_y)
		&& y <= data->game.m_h * (pos_y + 1))
	{
		x = (data->game.m_w * pos_x) + 1;
		pixel_x = 0;
		while (x > (data->game.m_w * pos_x)
			&& x <= data->game.m_w * (pos_x + 1))
		{	
			pixel_x += data->draw.scale_x;
			data->draw.color = data->tex[index].addr[data->tex[index].img_width
				* (int)(pixel_y) + (int)(pixel_x)];
			if ((data->draw.color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(x, y, data->draw.color, data);
			x++;
		}
		pixel_y += data->draw.scale_y;
		y++;
	}
}

void		draw_mob(t_data *data, int pos_x, int pos_y)
{
	int index;

	index = 5;
	while (index < 8)
	{
		draw_square(data, pos_x, pos_y, index);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_clear_window(data->mlx, data->win);
		index++;
	}
}

void	draw_game(t_data *data)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			/*if (data->map[y][x]  == '0')
				index = 0;*/
			if (data->map[y][x] == '1')
				draw_square(data, x, y, 1);
			else if (data->map[y][x] == 'C')
				draw_square(data, x, y, 2);
			/*else if (data->map[y][x] == 'E')
				index = 3;*/
			x++;
		}
		y++;
	}
	draw_square(data, data->game.door_x, data->game.door_y, 3);
	draw_square(data, data->game.x, data->game.y, 4);
}

static void	draw_floor(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != '1')
				draw_square(data, x, y, 0);
			x++;
		}
		y++;
	}
}

static void	draw_mini_square(t_data *data, int x, int y)
{
	int	x_max;
	int	y_max;

	y_max = y + 20;
	x_max = x + 20;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			my_mlx_pixel_put(x, y, 1, data);
			x++;
		}
		y++;
	}
}

int	render_next_frame(t_data *data)
{
	if (data->game.frame == 8)
		data->game.frame = 5;
	if (data->game.step >= 0)
	{
		mlx_clear_window(data->mlx, data->win);
		draw_floor(data);
		draw_game(data);
		draw_mini_square(data, 0, 0);
		draw_square(data, data->game.mob_x, data->game.mob_y, data->game.frame);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0,0);
		mlx_string_put(data->mlx, data->win, 5, 15, 16777215, data->game.step_str);
		data->game.frame++;
		if (((int)data->game.y == data->game.mob_y && (int)data->game.x == data->game.mob_x))
			data->game.step = -1;
	}
	else
		mlx_string_put(data->mlx, data->win, data->w_w/2, data->w_h/2, 16777215, ("GAME OVER !!! MOOOOUUUUAHAHAHA"));
	return (0);
}
