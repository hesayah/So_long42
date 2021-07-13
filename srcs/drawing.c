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

static	void		draw_map_two(t_data *data, int x , int y, int px, int py)
{
	if (data->map[py][px]
	&& data->map[py][px] == '0')
		my_mlx_pixel_put(x, y, 0x2F4F4F, data);
	else if (data->map[py][px]
	&& data->map[py][px] == 'C')
		my_mlx_pixel_put(x, y, 0xD3D3D3, data);
	else if (data->map[py][px]
	&& data->map[py][px] == 'P')
		my_mlx_pixel_put(x, y, 0021131000, data);
}

void				draw_map(t_data *data)
{
	int x;
	int y;
	int px;
	int py;

	y = 1;
	py = 0;
	while (py < data->game.m_h)
	{
		x = 1;
		px = 0;
		while (px < data->game.m_w)
		{
			if (x % (int)data->game.map_x == 0)
			{
				px++;
				x++;
			}
			draw_map_two(data, x,y,px,py);
			x++;
		}
		y++;
		if ((y % (int)data->game.map_y) == 0)
		{
			py++;
			y++;
		}
	}
}

int					render_next_frame(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
