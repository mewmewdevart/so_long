/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:16:52 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 13:42:26 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	return ;
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
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.wall);
	mlx_destroy_image(game_init->mlx_ptr, game_init->game_objs.floor);
	game_init->game_objs = (t_game_objs){0};
}
