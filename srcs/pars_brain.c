/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_brain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:11:31 by hesayah           #+#    #+#             */
/*   Updated: 2021/08/05 19:41:35 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_nb(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	free(line);
	close(fd);
	i++;
	return (i);
}

static int	get_map(char *file, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	i = get_nb(file);
	fd = open(file, O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!data->map)
		return (0);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			return (0);
		free(line);
		i++;
	}
	data->map[i] = ft_strdup(line);
	if (!data->map[i])
		return (0);
	data->map[i + 1] = NULL;
	free(line);
	return (1);
}

int	pars_brain(char *file, t_data *data)
{
	if (!get_map(file, data))
		return (0);
	if (!pars_map(data))
		return (0);
	return (1);
}
