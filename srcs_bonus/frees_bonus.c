#include "../include/so_long_bonus.h"

// Function to free the matrice[][]
void	ft_free_map(t_game_instance *game_init)
{
	int	i;

	if (game_init->map_init.matrice == NULL)
		return ;
	i = 0;
	while (game_init->map_init.matrice[i])
	{
		free(game_init->map_init.matrice[i]);
		i++;
	}
	free(game_init->map_init.matrice);
	game_init->map_init.matrice = NULL;
}

// Function to free all images.xpm
void	ft_free_img(t_game_instance *game_init)
{
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_up);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_left);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_right);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.player_down);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.collectible);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.exit_open);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.exit_close);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.enemy);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.floor);
}
