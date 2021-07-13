#include "../so_long.h"

int		close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	//clean_up(data);
	exit(0);
	return (0);
}

static	void	move(int keycode, t_data *data)
{
	if	(keycode ==  119 && data->map[data->game.y - 1][data->game.x] != '1')
		data->game.y--;
	else if (keycode == 115 && data->map[data->game.y + 1][data->game.x] != '1')
		data->game.y++;
	else if (keycode == 100 && data->map[data->game.y][data->game.x+ 1] != '1')
		data->game.x++;
	else if (keycode == 97 && data->map[data->game.y][data->game.x- 1] != '1')
		data->game.x--;
	data->map[data->game.y][data->game.x] == 'P';
	int i = 0;
	while (data->map[i])
	{
		printf("[%s]\n", data->map[i]);
		i++;
	}

}

int				action_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		return(close_window(data));
	else if (keycode == 119 || keycode == 97 || keycode == 100 ||
	keycode == 115)
	{
		printf("[x == %i && y == %i] \n", data->game.x, data->game.y);
		data->map[data->game.y][data->game.x] == '0';
		move(keycode, data);
	}
	render_next_frame(data);	
	return (0);
}