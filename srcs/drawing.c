/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 03:55:26 by hesayah           #+#    #+#             */
/*   Updated: 2021/07/08 03:57:46 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void				draw_map(t_data *data)
{
	data->maps.y = 1;
	data->maps.py = 0;
	while (data->maps.py < data->maps.m_y)
	{
		data->maps.x = 1;
		data->maps.px = 0;
		while (data->maps.px < data->maps.m_x)
		{
			if (data->maps.x % (int)data->maps.map_x == 0)
			{
				data->maps.px++;
				data->maps.x++;
			}
			draw_map_two(data);
			data->maps.x++;
		}
		data->maps.y++;
		if ((data->maps.y % (int)data->maps.map_y) == 0)
		{
			data->maps.py++;
			data->maps.y++;
		}
	}
}