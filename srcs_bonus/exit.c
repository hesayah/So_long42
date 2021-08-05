/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:18:50 by hesayah           #+#    #+#             */
/*   Updated: 2021/08/05 17:47:42 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	clean_up_two(t_data *data)
{
	if (data->game.step_str)
		free(data->game.step_str);
	if (data->tex[0].img)
		mlx_destroy_image(data->mlx, data->tex[0].img);
	if (data->tex[1].img)
		mlx_destroy_image(data->mlx, data->tex[1].img);
	if (data->tex[2].img)
		mlx_destroy_image(data->mlx, data->tex[2].img);
	if (data->tex[3].img)
		mlx_destroy_image(data->mlx, data->tex[3].img);
	if (data->tex[4].img)
		mlx_destroy_image(data->mlx, data->tex[4].img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	clean_up(t_data *data)
{
	if (data->map)
		ft_free(data->map);
	if (data->tex[0].r_path)
		free(data->tex[0].r_path);
	if (data->tex[1].r_path)
		free(data->tex[1].r_path);
	if (data->tex[2].r_path)
		free(data->tex[2].r_path);
	if (data->tex[3].r_path)
		free(data->tex[3].r_path);
	if (data->tex[4].r_path)
		free(data->tex[4].r_path);
	clean_up_two(data);
	exit(0);
	return (0);
}
