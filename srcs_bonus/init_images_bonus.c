/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:10:36 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 19:28:26 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// Function to loads the different game images in (XPM format)
void	ft_img_init(t_game_instance *game_init)
{
	ft_check_img(game_init, &game_init->game_objs.player_up,
		"rscs/textures/Player/walkUP_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_down,
		"rscs/textures/Player/walkDown_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_right,
		"rscs/textures/Player/walkRight_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.player_left,
		"rscs/textures/Player/walkLeft_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.collectible,
		"rscs/textures/Collectibles/star_00.xpm");
	ft_check_img(game_init, &game_init->game_objs.floor,
		"rscs/textures/Tiles/midBlocks_02.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_open,
		"rscs/textures/Exit/exit_open_01.xpm");
	ft_check_img(game_init, &game_init->game_objs.exit_close,
		"rscs/textures/Exit/exit_close_01.xpm");
	ft_check_img(game_init, &game_init->game_objs.enemy,
		"rscs/textures/Enemy/enemy_00.xpm");
	ft_wall_init(game_init);
}

void	ft_wall_init(t_game_instance *game_init)
{
	ft_check_img(game_init, &game_init->game_objs.wall_up0,
		"rscs/textures/Tiles/topBlocks_01.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall_up1,
		"rscs/textures/Tiles/topBlocks_02.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall_up2,
		"rscs/textures/Tiles/topBlocks_03.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall_middle0,
		"rscs/textures/Tiles/midBlocks_01.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall_middle1,
		"rscs/textures/Tiles/block.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall_middle2,
		"rscs/textures/Tiles/midBlocks_03.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall_down0,
		"rscs/textures/Tiles/botBlocks_01.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall_down1,
		"rscs/textures/Tiles/botBlocks_02.xpm");
	ft_check_img(game_init, &game_init->game_objs.wall_down2,
		"rscs/textures/Tiles/botBlocks_03.xpm");
}

// Function to validate the files .xpm
void	ft_check_img(t_game_instance *game_init, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game_init->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{	
		ft_error_init(1);
		ft_exit_program(game_init);
	}
}
