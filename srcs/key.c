#include "../so_long.h"

int		close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	//clean_up(data);
	return (0);
}

static	void	move(int keycode, t_data *data)
{
	if	(keycode ==  119 && data->map[data->game.y--][data->game.x] != '1')
		data->game.y--;
	else if (keycode == 115 && data->map[data->game.y++][data->game.x] != '1')
		data->game.y++;
	else if (keycode == 100 && data->map[data->game.y][data->game.x++] != '1')
		data->game.x++;
	else if (keycode == 97 && data->map[data->game.y][data->game.x--] != '1')
		data->game.x--;
}

int				action_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 119 || keycode == 113 || keycode == 122 ||
	keycode == 115)
		move(keycode, data);
	render_next_frame(data);
	return (0);
}