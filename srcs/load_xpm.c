/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 01:13:23 by hesayah           #+#    #+#             */
/*   Updated: 2021/07/08 03:51:42 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		load_xpm(t_data *data)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (!(data->t[i].img = mlx_xpm_file_to_image(data->mlx,
		data->t[i].r_path, &data->t[i].img_width, &data->t[i].img_height)))
		{
			exit_error(11, data);
			return (0);
		}
		(data->t[i].addr = (int*)mlx_get_data_addr(data->t[i].img,
		&data->t[i].bits_per_pixel, &data->t[i].line_length,
		&data->t[i].endian));
		i++;
	}
	return (1);
}
