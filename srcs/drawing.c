#include "../so_long.h"

void			my_mlx_pixel_put(int x, int y, int color, t_data *data)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned	long	ft_rgb(int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return ((int)(-1));
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void			draw_sprite(t_data *data, int  xx, int  yy)
{
	int y;
	int x;

	x = xx;
	while (x++ < xx)
	{
		{
			y = yy + 1;
			while (y++ < ((yy + 1) % data->game. )
			{
				data->tex.pixel = (y) * 256 - data->game.m_h * 128
				+ data->srt.srt_h * 128;
				data->tex.y = ((data->tex.pixel * data->tex[4].img_height)
				/ data->game.m_w / 256;
				data->rgb.color = data->tex[4].addr[data->tex[4].img_width
				* data->tex.y + data->tex.x];
				if ((data->tex.color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(x, y, data->tex.color, data);
			}
		}
	}
}

void		draw_map(t_data *data)
{
	int x;
	int y;
	int px;
	int py;

	y = 1;
	py = 0;
	while (py < data->game.map_y)
	{
		x = 1;
		px = 0;
		while (px < data->game.map_x)
		{
			if (x % (int)data->game.m_w == 0)
			{
				px++;
				x++;
			}
			draw_map_two(data, x,y,px,py);
			x++;
		}
		y++;
		if ((y % (int)data->game.m_h) == 0)
		{
			py++;
			y++;
		}
	}
}

/*static	void		draw_map_two(t_data *data, int x , int y, int px, int py)
{
	if (data->map[py][px]
	&& data->map[py][px] == '0')
		my_mlx_pixel_put(x, y, 0x2F4F4F, data);
	else if (data->map[py][px]
	&& data->map[py][px] == 'C')
		my_mlx_pixel_put(x, y, 0xD3D3D3, data);
	else if (data->map[py][px]
	&& data->map[py][px] == '1')
		my_mlx_pixel_put(x, y, 0021131000, data);
	else if (data->map[py][px]
	&& data->map[py][px] == '0')
		my_mlx_pixel_put(x, y, 0xFFFFFFF, data);
	else if (data->map[py][px]
	&& data->map[py][px] == 'P')
		my_mlx_pixel_put(x, y, 0x5555, data);*/
}

/*void				draw_map(t_data *data)
{
	int x;
	int y;
	int px;
	int py;

	y = 1;
	py = 0;
	while (py < data->game.map_y)
	{
		x = 1;
		px = 0;
		while (px < data->game.map_x)
		{
			if (x % (int)data->game.m_w == 0)
			{
				px++;
				x++;
			}
			draw_map_two(data, x,y,px,py);
			x++;
		}
		y++;
		if ((y % (int)data->game.m_h) == 0)
		{
			py++;
			y++;
		}
	}
}*/

int					render_next_frame(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
