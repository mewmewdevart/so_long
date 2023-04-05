/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:06:23 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/30 14:34:20 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_initialize_game(t_game_instance *game_init)
{
	game_init->mlx_ptr = mlx_init();
	if (game_init->mlx_ptr == NULL)
		ft_error_init(38);

	game_init->win_ptr = mlx_new_window(game_init->mlx_ptr, game_init->map_init.resolutions.settings_map_width*CELL_SIZE, game_init->map_init.resolutions.settings_map_height*CELL_SIZE, game_init->resolutions_init.settings_name_window);
	if (game_init->win_ptr == NULL)
		ft_error_init(38);

	game_init->game_data.count_movements = 0;

	ft_printf("Estou dentro do game_init\n");
	int i;
	i = 0;
	while(game_init->map_init.matrice[i])
	{
		ft_printf("%s",game_init->map_init.matrice[i]);
		i++;
	}

	ft_img_init(game_init);
	game_init->game_objs.player = game_init->game_objs.player_down;
}

void ft_img_init(t_game_instance *game_init)
{
	game_init->game_objs.player_up = mlx_xpm_file_to_image(game_init->mlx_ptr, "../rscs/sprites/Player/walkUP_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.player_left = mlx_xpm_file_to_image(game_init->mlx_ptr, "../rscs/sprites/Player/walkLeft_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.player_down = mlx_xpm_file_to_image(game_init->mlx_ptr, "../rscs/sprites/Player/walkDown_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.player_right = mlx_xpm_file_to_image(game_init->mlx_ptr, "../rscs/sprites/Player/walkRight_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.collectible = mlx_xpm_file_to_image(game_init->mlx_ptr, "../rscs/sprites/Player/star_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.floor = mlx_xpm_file_to_image(game_init->mlx_ptr,  "../rscs/sprites/Tiles/midBlocks_02.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.exit_open = mlx_xpm_file_to_image(game_init->mlx_ptr, "../rscs/sprites/Exit/exit_open_01.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
	game_init->game_objs.exit_close = mlx_xpm_file_to_image(game_init->mlx_ptr, "../rscs/sprites/Exit/exit_close_01.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height); //CHANGE THE CONRRECT PATH TO SPRITE
	game_init->game_objs.wall = mlx_xpm_file_to_image(game_init->mlx_ptr,  "../rscs/sprites/Tiles/topBlocks_02.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
}

/* ESSA FUNÇÃO É PRA CHECAR QUANDO RETORNA NULL NO MLX_XPM_FILE_TO_IMAGE
void ft_checker_img(t_game_instance *game_init, void **image, char *path_img)
{
	int width;
	int height;

	*image = mlx_xpm_file_to_image(game_init->mlx_ptr, path_img, &width, &height);
	//if (*image == NULL)
	//{
		//ft_error_init(38);
		//ft_exit_program(game_init);
	//}
}*/