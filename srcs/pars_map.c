/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:02:35 by hesayah           #+#    #+#             */
/*   Updated: 2021/08/02 23:11:13 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_value(char *map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		if (ft_c_in_str(map[x], "01CEP") == 0)
			return (0);
		x++;
	}
	return (1);
}

static int	check_if_rec(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= data->game.m_h)
		if (data->map[y][0] != '1')
			return (0);
	y = -1;
	while (++y <= data->game.m_h)
		if (data->map[y][(int)data->game.map_x] != '1')
			return (0);
	x = -1;
	while (++x <= data->game.m_w)
		if (data->map[x][0] != '1')
			return (0);
	x = -1;
	while (++x <= data->game.m_w)
		if (data->map[x][(int)data->game.map_y] != '1')
			return (0);
	if (data->game.spown > 1)
		return (0);
	return (1);
}

int	init_map_value(t_data *data, int x, int y)
{
	if (!check_if_rec(data))
		return (0);
	load_xpm(data);
	data->game.map_x = x;
	data->game.map_y = y;
	data->game.m_w = (data->w_max) / (data->game.map_x);
	data->game.m_h = (data->h_max) / (data->game.map_y);
	if (data->game.m_w < data->game.m_h)
		data->game.m_h = data->game.m_w;
	else
		data->game.m_w = data->game.m_h;
	data->w_w = data->game.m_w * (int)data->game.map_x;
	data->w_h = data->game.m_h * (int)data->game.map_y;
}

void	assigne_value(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'C')
		data->game.collect++;
	else if (data->map[y][x] == 'P')
	{
		data->game.x = x;
		data->game.y = y;
		data->game.spown++;
	}
	else if (data->map[y][x] == 'E')
	{
		data->game.door_x = x;
		data->game.door_y = y;
		data->map[y][x] == '0';
	}
}

int	pars_map(t_data *data)
{
	int	x;
	int	y;
	int	len;

	y = 0;
	len = ft_strlen(data->map[0]);
	while (data->map[y])
	{
		if (!check_value(data->map[y]) || len != ft_strlen(data->map[y]))
			return (0);
		x = 0;
		while (data->map[y][x])
		{
			assigne_value(data, x, y);
			x++;
		}
		y++;
	}
	return (init_map_value(data, len, y));
}
