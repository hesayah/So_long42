/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 03:16:17 by hesayah           #+#    #+#             */
/*   Updated: 2021/07/08 03:31:52 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int				clean_up(t_data *data)
{
	if (data->tab)
		ft_free(data->tab);
	if (data->map)
		ft_free(data->map);
	if (data->t[0].r_path)
		free(data->t[0].r_path);
	if (data->t[1].r_path)
		free(data->t[1].r_path);
	if (data->t[2].r_path)
		free(data->t[2].r_path);
	if (data->t[3].r_path)
		free(data->t[3].r_path);
	if (data->t[4].r_path)
		free(data->t[4].r_path);
	return (0);
}

void			exit_error(int code, t_data *data)
{
	if (code == -1)
		ft_putstr_fd("ERROR : MALLOC FAIL\n", 0);
	if (code == 0)
		ft_putstr_fd("ERROR : BAD EXTENTION OR EMPTY\n", 0);
	if (code == 1)
		ft_putstr_fd("ERROR : PARSING MAP WRONG INPUT\n", 0);
	if (code == 2)
		ft_putstr_fd("ERROR : PARSING WRONG ID\n", 0);
	if (code == 3)
		ft_putstr_fd("ERROR : PARSING GETTING RESOLUTION\n", 0);
	if (code > 8)
		data->err = -2;
	else
		data->err = -1;
}

void			code_err(int code)
{
	if (code != 0)
		write(0, strerror(code), ft_strlen(strerror(code)));
	write(0, "\n", 1);
}
