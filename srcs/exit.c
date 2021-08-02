#include "../so_long.h"

int				clean_up(t_data *data)
{

	if (data->map)
		ft_free(data->map);
	if (data->)
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}