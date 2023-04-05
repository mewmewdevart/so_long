#include "../include/so_long.h"

// Draw the map in the correct positions
int ft_map_draw(t_game_instance *game_init)
{
	int row;
	int column;

    // row is lines
	row = 0;
	while (game_init->map_init.matrice[row])
	{
		column = 0;
		while (game_init->map_init.matrice[row][column])
		{
			if (game_init->map_init.matrice[row][column] == WALL)
					ft_settings_draw(game_init, game_init->game_objs.wall, column, row);
			if (game_init->map_init.matrice[row][column] == EMPTY)
					ft_settings_draw(game_init, game_init->game_objs.floor,  column, row);
			if (game_init->map_init.matrice[row][column] == PLAYER)
					ft_settings_draw(game_init, game_init->game_objs.player,  column, row);
			if (game_init->map_init.matrice[row][column] == EXIT && game_init->game_objs.collectible != 0)
					ft_settings_draw(game_init, game_init->game_objs.exit_close,  column, row);
			if (game_init->map_init.matrice[row][column] == EXIT && game_init->game_objs.collectible == 0)
					ft_settings_draw(game_init, game_init->game_objs.exit_open, column, row);
			if (game_init->map_init.matrice[row][column] == COLLECTIBLE)
					ft_settings_draw(game_init, game_init->game_objs.collectible, column, row);
			column++;
        }
		row++;
    }
	return (ft_player_moves(game_init));
}

// Display the movements on screen
int ft_player_moves(t_game_instance *game_init)
{
	char *movements;

	mlx_string_put(game_init->mlx_ptr, game_init->win_ptr, 12, 16, 0x00FFFFFF, "Moves: ");
	movements = ft_itoa (game_init->game_data.count_movements);
	mlx_string_put(game_init->mlx_ptr, game_init->win_ptr, 60, 16, 0x00FFFFFF, movements);
	free(movements);
	return (0);
}

// Put the image in the screen
void ft_settings_draw(t_game_instance *game_init, void *image, int width, int height)
{
    mlx_put_image_to_window(game_init->mlx_ptr, game_init->win_ptr, image, width * CELL_SIZE , height * CELL_SIZE );
}