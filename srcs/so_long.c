/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 22:57:42 by hesayah           #+#    #+#             */
/*   Updated: 2021/08/05 19:39:50 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	loop_hook(t_data *data)
{
	data->win = mlx_new_window(data->mlx, data->w_w,
			data->w_h, "HeSayah SoLong");
	data->img = mlx_new_image(data->mlx, data->w_w, data->w_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mlx_hook(data->win, 33, 1L << 17, close_window, data);
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_hook(data->win, 2, 1L << 0, action_key, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
}

int	check_ext(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, __O_DIRECTORY);
	if (fd != -1)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = get_next_line(fd, &line);
	free(line);
	if (!i)
		return (0);
	close(fd);
	i = 0;
	while (file[i] != '\0' && file[i] != '.')
		i++;
	if (ft_strncmp(file + i, ".ber", 5) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		ret;
	t_data	data;

	ret = check_ext(argv[1]);
	if (!ret || argc < 1)
	{
		ft_putstr_fd("Error : check map.ber\n", 0);
		return (0);
	}
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_putstr_fd("ERROR : CONNEXTION TO MLX FAILED!\n", 0);
		return (0);
	}
	init_data(&data);
	ret = pars_brain(argv[1], &data);
	if (!ret)
	{
		ft_putstr_fd("Error : LOADING GAME FAIL\n", 0);
		clean_up(&data);
		return (0);
	}
	loop_hook(&data);
	ft_free(data.map);
}
