/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:24:50 by hesayah           #+#    #+#             */
/*   Updated: 2021/08/05 17:43:46 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_path_tex(t_data *data)
{
	data->tex[0].r_path = ft_strdup("srcs/img/floor.xpm");
	if (!data->tex[0].r_path)
		return (0);
	data->tex[1].r_path = ft_strdup("srcs/img/wall.xpm");
	if (!data->tex[1].r_path)
		return (0);
	data->tex[2].r_path = ft_strdup("srcs/img/collect.xpm");
	if (!data->tex[2].r_path)
		return (0);
	data->tex[3].r_path = ft_strdup("srcs/img/door.xpm");
	if (!data->tex[3].r_path)
		return (0);
	data->tex[4].r_path = ft_strdup("srcs/img/player.xpm");
	if (!data->tex[4].r_path)
		return (0);
	data->tex[5].r_path = ft_strdup("srcs/img/mob_one.xpm");
	if (!data->tex[5].r_path)
		return (0);
	data->tex[6].r_path = ft_strdup("srcs/img/mob_two.xpm");
	if (!data->tex[6].r_path)
		return (0);
	data->tex[7].r_path = ft_strdup("srcs/img/mob_three.xpm");
	if (!data->tex[7].r_path)
		return (0);
	return (1);
}

int	load_xpm(t_data *data)
{
	int	i;

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
