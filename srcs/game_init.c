/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:06:23 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/30 14:34:20 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_sprites_init(t_game_instance *game_init);

void	ft_initialize_game(t_game_instance *game_init)
{
	game_init->mlx_ptr = mlx_init();
	if (game_init->mlx_ptr == NULL)
		ft_error_init(38);

	game_init->win_ptr = mlx_new_window(game_init->mlx_ptr, game_init->map_init.resolutions.settings_map_width*CELL_SIZE, game_init->map_init.resolutions.settings_map_height*CELL_SIZE, game_init->resolutions_init.settings_name_window);
	if (game_init->win_ptr == NULL)
		ft_error_init(38);

	game_init->game_data.count_movements = 0;
	game_init->game_data.endgame = 0;

	ft_sprites_init(game_init);
	ft_show_game(game_init);
}


void ft_sprites_init(t_game_instance *game_init)
{
	game_init->game_objs.player = mlx_xpm_file_to_image (game_init->mlx_ptr, "../rscs/sprites/Player_idle/idleAnim_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
		//game_init->game_objs.player_up = mlx_xpm_file_to_image (game_init->mlx_ptr, "../rscs/sprites/Player_walkUp/walkAnimUp_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
		//game_init->game_objs.player_right = mlx_xpm_file_to_image (game_init->mlx_ptr, "../rscs/sprites/Player_walkRight/walkAnimRight_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
		//game_init->game_objs.player_left = mlx_xpm_file_to_image (game_init->mlx_ptr, "../rscs/sprites/Player_walkLeft/walkAnimLeft_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
		//game_init->game_objs.player_down = mlx_xpm_file_to_image (game_init->mlx_ptr, "../rscs/sprites/Player_walkDown/walkAnimDown_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.collectible = mlx_xpm_file_to_image (game_init->mlx_ptr, "../rscs/sprites/Collectibles/starAnim1.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.wall = mlx_xpm_file_to_image (game_init->mlx_ptr,  "../rscs/sprites/Tiles/wallLeftMidle.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.exit_on = mlx_xpm_file_to_image (game_init->mlx_ptr, "../rscs/sprites/Exit/door.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.floor = mlx_xpm_file_to_image (game_init->mlx_ptr, "../rscs/sprites/Tiles/freeFloor.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);

}