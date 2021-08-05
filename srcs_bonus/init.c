/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:18:43 by hesayah           #+#    #+#             */
/*   Updated: 2021/08/05 19:31:33 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_data_two(t_data *data)
{
	data->map = NULL;
	data->game.step_str = NULL;
	data->tex[0].r_path = NULL;
	data->tex[1].r_path = NULL;
	data->tex[2].r_path = NULL;
	data->tex[3].r_path = NULL;
	data->tex[4].r_path = NULL;
	data->tex[5].r_path = NULL;
	data->tex[6].r_path = NULL;
	data->tex[7].r_path = NULL;
	data->tex[0].img = NULL;
	data->tex[1].img = NULL;
	data->tex[2].img = NULL;
	data->tex[3].img = NULL;
	data->tex[4].img = NULL;
	data->tex[5].img = NULL;
	data->tex[6].img = NULL;
	data->tex[7].img = NULL;
}

void	init_data(t_data *data)
{
	data->w_h = 0;
	data->w_w = 0;
	mlx_get_screen_size(data->mlx, &data->w_max, &data->h_max);
	data->game.collect = 0;
	data->game.spown = 0;
	data->game.step = 20;
	data->game.frame = 5;
	data->game.mob_x = 1;
	data->game.mob_y = 1;
	data->err = 0;
	init_data_two(data);
}
