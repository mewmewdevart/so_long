#include "../include/so_long_bonus.h"

// Function to initializes the game window and sets the initial properties of the game
void	ft_initialize_game(t_game_instance *game_init)
{
	game_init->mlx_ptr = mlx_init();
	if (game_init->mlx_ptr == NULL)
		ft_error_init(38);
	game_init->win_ptr = mlx_new_window(game_init->mlx_ptr, game_init->map_init.resolutions.settings_map_width * CELL_SIZE, game_init->map_init.resolutions.settings_map_height * CELL_SIZE, "The Blue Knight");
	if (game_init->win_ptr == NULL)
		ft_error_init(38);
	game_init->game_data.count_movements = 0;
	ft_img_init(game_init);
	game_init->game_objs.player = game_init->game_objs.player_down;
}

// Function to loads the different game images (player, collectibles, floor, exit, and walls) from image files (XPM format)
void	ft_img_init(t_game_instance *game_init)
{
	game_init->game_objs.player_up = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Player/walkUP_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.player_left = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Player/walkLeft_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.player_down = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Player/walkDown_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.player_right = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Player/walkRight_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.collectible = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Collectibles/star_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.floor = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Tiles/midBlocks_02.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.exit_open = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Exit/exit_open_01.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.exit_close = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Exit/exit_close_01.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	ft_wall_init(game_init);
	game_init->game_objs.enemy = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Enemy/enemy_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
}


void	ft_wall_init(t_game_instance *game_init)
{
	game_init->game_objs.wall_up0 = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Tiles/topBlocks_01.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.wall_up1 = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Tiles/topBlocks_02.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.wall_up2 = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Tiles/topBlocks_03.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);

	game_init->game_objs.wall_middle0 = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Tiles/midBlocks_01.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.wall_middle1 = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Tiles/block.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height); //need to be checked
	game_init->game_objs.wall_middle2 = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Tiles/midBlocks_03.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);

	game_init->game_objs.wall_down0 = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Tiles/botBlocks_01.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.wall_down1 = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Tiles/botBlocks_02.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.wall_down2 = mlx_xpm_file_to_image(game_init->mlx_ptr, "rscs/sprites/Tiles/botBlocks_03.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
}
