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

int		load_xpm(t_data *data)
{
	int i;

	data->tex[0].r_path = ft_strdup("srcs/img/herbe.xpm");
	data->tex[1].r_path = ft_strdup("srcs/img/wall.xpm");
	data->tex[2].r_path = ft_strdup("srcs/img/miel.xpm");
	data->tex[3].r_path = ft_strdup("srcs/img/porte.xpm");
	data->tex[4].r_path = ft_strdup("srcs/img/test2.xpm");
	i = 0;
	while (i < 5)
	{
		if (!(data->tex[i].img = mlx_xpm_file_to_image(data->mlx,
		data->tex[i].r_path, &data->tex[i].img_width, &data->tex[i].img_height)))
		{
			printf("Error : Loading textures\n");
			return (0);
		}
		(data->tex[i].addr = (int*)mlx_get_data_addr(data->tex[i].img,
		&data->tex[i].bits_per_pixel, &data->tex[i].line_length,
		&data->tex[i].endian));
		i++;
	}
	return (1);
}

static	void			scale(int *scale_x, int *scale_y, int index, t_data *data)
{
	if (data->tex[index].img_width > data->game.m_w)
		*scale_x = (int)(data->tex[index].img_width / data->game.m_w);
	else
		*scale_x = (int)(data->game.m_w / data->tex[index].img_width);
	if (data->tex[index].img_height > data->game.m_h)
		*scale_y = (int)(data->tex[index].img_height / data->game.m_h);
	else
		*scale_y = (int)(data->game.m_h / data->tex[index].img_height);
}

static	void			draw_square(t_data *data, int  pos_x, int  pos_y, int  index)
{
	int y;
	int x;
	int	scale_x;
	int	scale_y;
	int	pixel_x;
	int	pixel_y;

	scale(&scale_x, &scale_y ,index,  data);
	y = (data->game.m_h * pos_y) + 1;
	pixel_y = scale_y;
	while (y > (data->game.m_h * pos_y) && y < data->game.m_h * (pos_y + 1))
	{
		x = (data->game.m_w * pos_x) + 1;
		pixel_x = scale_x;
		while (x > (data->game.m_w * pos_x) && x < data->game.m_w * (pos_x + 1))
		{	
			pixel_x += scale_x;
			data->draw.color = data->tex[index].addr[(int)(data->tex[index].img_width
			* pixel_y + pixel_x)];
			//if (data->draw.color != 16777215)
				my_mlx_pixel_put(x, y , data->draw.color, data);
			x++;
		}
		pixel_y += scale_y;
		y++;
	}
}

void		draw_map(t_data *data)
{
	int	x;
	int	y;
	int index;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x]  == '0')
				index = 0;
			else if (data->map[y][x] == '1')
				index = 1;
			else if (data->map[y][x] == 'C')
				index = 2;
			else if (data->map[y][x] == 'E')
				index = 3;
			else if  (data->map[y][x] == 'P')
				index = 4;
			if (index != -1)
				draw_square(data, x, y, index);
			x++;
		}
		y++;
	}
}

static void	draw_back(t_data *data)
{
	int x;
	int y;

	y = 0; 
	while (y < data->w_h)
	{
		x = 0;
		while (x < data->w_w)
		{
			my_mlx_pixel_put(x,y, 174502, data);
			x++;
		}
		y++;
	}
}

int					render_next_frame(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	draw_back(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
