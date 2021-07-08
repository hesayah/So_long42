/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 03:42:44 by hesayah           #+#    #+#             */
/*   Updated: 2021/07/08 03:59:59 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int		close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	clean_up(data);
	return (0);
}

static	void	move(int keycode, t_data *data)
{
	if	(keycode ==  && )
	{
		data->m_y--;
	}
	else if ()
	{
		data->m_y++;
	}
	else if ()
	{
		data->m_x--;
	}
	else if ()
	{
		data->m_x++;

	}
}

int				action_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 100 || keycode == 113 || keycode == 122 ||
	keycode == 115)
		move(keycode, data);
	return (0);
}

int					render_next_frame(keycode, t_data *data)
{
	action_key(keycode, data);
	draw_map(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

