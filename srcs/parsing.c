/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 00:57:39 by hesayah           #+#    #+#             */
/*   Updated: 2021/07/08 03:51:35 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_map_two(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (c_in_str(tab[i], "012CEP") == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static void	check_value_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->tab[i] && (c_in_str(data->tab[i][0], "CEP") == 1 ||
	(int)data->tab[i][0] == 0))
		i++;
	while (data->tab[i] && c_in_str(data->tab[i][0], " 012") == 1)
	{
		if (check_map_two(data->tab[i]) == 0)
			return (exit_error(1, data));
		if (data->m_x != ft_strlen(data->tab[i]))
			return (exit_error(1, data));
		i++;
		data->max_y++;
	}
	while (data->tab[i])
	{
		if (c_in_str(data->tab[i][0], "012") == 1)
			return (exit_error(1, data));
		i++;
	}
}

int			get_nb(char *file, t_data *data)
{
	int		i;
	int		x;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		data->max_x = ft_strlen(line);
		free(line);
	}
	free(line);
	close(fd);
	i++;
	return (i);
}

void		pars_brain(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	i = get_nb(file, data) + 1;
	fd = open(file, O_RDONLY);
	if (!(data->tab =
	(char**)malloc(sizeof(char *) * (i + 1))))
		return (exit_error(-1, data));
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		data->tab[i] = ft_strdup(line);
		free(line);
		i++;
	}
	data->tab[i] = ft_strdup(line);
	data->tab[i + 1] = NULL;
	free(line);
	check_value_map(data);
	pars_value_line(data);
}
