/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:02:34 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 17:37:33 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_anim_collectable(t_game_instance *game_init)
{
	if (game_init->game_data.anim_collectible >= 3)
		game_init->game_data.anim_collectible = 0;
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.collectible);
	if (game_init->game_data.anim_collectible == 0)
		game_init->game_objs.collectible
			= mlx_xpm_file_to_image(game_init->mlx_ptr,
				"rscs/textures/Collectibles/star_00.xpm",
				&game_init->game_objs.img_width,
				&game_init->game_objs.img_height);
	else if (game_init->game_data.anim_collectible == 1)
		game_init->game_objs.collectible
			= mlx_xpm_file_to_image(game_init->mlx_ptr,
				"rscs/textures/Collectibles/star_01.xpm",
				&game_init->game_objs.img_width,
				&game_init->game_objs.img_height);
	else if (game_init->game_data.anim_collectible == 2)
		game_init->game_objs.collectible
			= mlx_xpm_file_to_image(game_init->mlx_ptr,
				"rscs/textures/Collectibles/star_02.xpm",
				&game_init->game_objs.img_width,
				&game_init->game_objs.img_height);
	game_init->game_data.anim_collectible++;
	ft_map_draw(game_init);
	return (0);
}
