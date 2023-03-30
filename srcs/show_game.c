#include "../include/so_long.h"

int	ft_show_game(t_game_instance *game_init)
{
	int	y_row;
	int	x_col;

	ft_printf("PRINTANDO A MATRIZ DE DENTRO DO FT_SHOW_GAME: %s", game_init->map_init.matrice);
	y_row = 0;
	while (game_init->map_init.matrice[y_row])
	{
		x_col = 0;
		while (game_init->map_init.matrice[y_row][x_col])
		{
			if (game_init->map_init.matrice[y_row][x_col] == WALL)
				ft_draw(game_init, game_init->game_objs.wall, x_col, y_row);
			else if (game_init->map_init.matrice[y_row][x_col] == EMPTY)
				ft_draw(game_init, game_init->game_objs.floor, x_col, y_row);
			else if (game_init->map_init.matrice[y_row][x_col] == PLAYER)
				ft_player_draw(game_init, game_init->game_objs.player, x_col,y_row);
			else if (game_init->map_init.matrice[y_row][x_col] == COLLECTIBLE)
				ft_draw(game_init, game_init->game_objs.collectible, x_col, y_row);
			else if (game_init->map_init.matrice[y_row][x_col] == EXIT)
				ft_draw_exit(game_init, x_col , y_row);
			x_col++;
		}
		y_row++;
	}
	return (0);
}

void	ft_draw(t_game_instance *game_init, void *image, int x, int y)
{
	mlx_put_image_to_window(game_init->mlx_ptr, game_init->win_ptr, image, x * CELL_SIZE, y * CELL_SIZE);
}


void ft_player_draw(t_game_instance *game_init, void *image, int x, int y)
{
	game_init->positions_init.player_row = y;
	game_init->positions_init.player_col = x;

	ft_draw(game_init, image, x, y);
} 

void ft_draw_exit (t_game_instance *game_init, int x, int y)
{
	if (game_init->game_data.count_collectible == 0)
	{
		mlx_destroy_image(game_init->mlx_ptr, game_init->win_ptr);
		game_init->game_objs.exit_on = mlx_xpm_file_to_image (game_init->mlx_ptr, "../rscs/sprites/Exit/door.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	}
	ft_draw(game_init, game_init->game_objs.exit_on, x , y);
}
