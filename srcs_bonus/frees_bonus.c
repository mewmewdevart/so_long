/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:04:51 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 16:05:28 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.floor);
	ft_free_wall(game_init);
}

void	ft_free_wall(t_game_instance *game_init)
{
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall_up0);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall_up1);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall_up2);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall_middle0);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall_middle1);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall_middle2);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall_down0);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall_down1);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall_down2);
}
