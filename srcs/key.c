/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:12:54 by hesayah           #+#    #+#             */
/*   Updated: 2021/08/02 23:18:05 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	clean_up(data);
	exit(0);
	return (0);
}

static int	move(int keycode, t_data *data)
{
	if (data->map[(int)data->game.y][(int)data->game.x] == 'C')
		data->game.collect--;
	if (data->map[(int)data->game.y][(int)data->game.x] != 'E')
		data->map[(int)data->game.y][(int)data->game.x] = '0';
	if (keycode == 119 && data->map[(int)(data->game.y - 1)]
		[(int)data->game.x] != '1')
		data->game.y = data->game.y - 1;
	else if (keycode == 115 && data->map[(int)(data->game.y + 1)]
		[(int)data->game.x] != '1')
		data->game.y = data->game.y + 1;
	else if (keycode == 100 && data->map[(int)data->game.y]
		[(int)(data->game.x + 1)] != '1')
		data->game.x = data->game.x + 1;
	else if (keycode == 97 && data->map[(int)data->game.y]
		[(int)(data->game.x - 1)] != '1')
		data->game.x = data->game.x - 1;
	if (data->map[(int)data->game.y][(int)data->game.x] == 'C')
		data->game.collect--;
	else if (data->map[(int)data->game.y][(int)data->game.x] == 'E'
	&& data->game.collect == 0)
		close_window(data);
	if (data->map[(int)data->game.y][(int)data->game.x] != 'E')
		data->map[(int)data->game.y][(int)data->game.x] = 'P';
}

int	action_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		return (close_window(data));
	else if (keycode == 119 || keycode == 97 || keycode == 100
		|| keycode == 115)
		move(keycode, data);
	return (0);
}
