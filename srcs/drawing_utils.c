/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:33:19 by hesayah           #+#    #+#             */
/*   Updated: 2021/08/02 23:33:56 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(int x, int y, int color, t_data *data)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned	long	ft_rgb(int r, int g, int b)
{
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return ((int)(-1));
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	load_xpm(t_data *data)
{
	int	i;

	data->tex[0].r_path = ft_strdup("srcs/img/floor.xpm");
	data->tex[1].r_path = ft_strdup("srcs/img/wall.xpm");
	data->tex[2].r_path = ft_strdup("srcs/img/collect.xpm");
	data->tex[3].r_path = ft_strdup("srcs/img/door.xpm");
	data->tex[4].r_path = ft_strdup("srcs/img/player.xpm");
	data->tex[5].r_path = ft_strdup("srcs/img/mob_one.xpm");
	data->tex[6].r_path = ft_strdup("srcs/img/mob_two.xpm");
	data->tex[7].r_path = ft_strdup("srcs/img/mob_three.xpm");
	i = 0;
	while (i < 8)
	{	
		data->tex[i].img = mlx_xpm_file_to_image(data->mlx,
				data->tex[i].r_path, &data->tex[i].img_width,
				&data->tex[i].img_height);
		if (!data->tex[i].img)
		{
			printf("Error : Loading textures\n");
			return (0);
		}
		(data->tex[i].addr = (int *)mlx_get_data_addr(data->tex[i].img,
					&data->tex[i].bits_per_pixel, &data->tex[i].line_length,
					&data->tex[i].endian));
		i++;
	}
	return (1);
}
