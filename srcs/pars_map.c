/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:02:35 by hesayah           #+#    #+#             */
/*   Updated: 2021/08/05 17:44:21 by hesayah          ###   ########.fr       */
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
		{
			ft_putstr_fd("ERROR : ERROR MAP\n", 0);
			return (0);
		}
		x++;
	}
	return (1);
}

static int	check_if_close(t_data *data)
{
	int	x;
	int	y;
	int	len_x;
	int	len_y;

	y = -1;
	len_x = data->game.map_x - 1;
	len_y = data->game.map_y - 1;
	while (data->map[++y])
		if (data->map[y][0] != '1')
			return (0);
	y = -1;
	while (data->map[++y])
		if (data->map[y][len_x] != '1')
			return (0);
	x = -1;
	while (data->map[0][++x])
		if (data->map[0][x] != '1')
			return (0);
	x = -1;
	while (data->map[len_y][++x])
		if (data->map[len_y][x] != '1')
			return (0);
	return (1);
}

static int	init_game_value(t_data *data, int x, int y)
{
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
	data->game.step_str = ft_itoa(data->game.step);
	if (!data->game.step_str)
		return (0);
	if (!check_if_close(data))
	{
		ft_putstr_fd("ERROR : MAP NOT CLOSE\n", 0);
		return (0);
	}
	if (!load_xpm(data))
		return (0);
	ft_putstr_fd(data->game.step_str, 0);
	ft_putstr_fd("\n", 0);
	return (1);
}

static void	assigne_value(t_data *data, int x, int y)
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

	y = -1;
	len = ft_strlen(data->map[0]);
	while (data->map[++y])
	{
		if (!check_value(data->map[y]))
			return (0);
		if (len != ft_strlen(data->map[y]))
		{
			ft_putstr_fd("ERROR : MAP NOT RECTANGLE\n", 0);
			return (0);
		}
		x = -1;
		while (data->map[y][++x])
			assigne_value(data, x, y);
	}
	if (data->game.spown > 1)
	{
		ft_putstr_fd("ERROR : SPOWN ERROR\n", 0);
		return (0);
	}
	return (init_game_value(data, len, y));
}
