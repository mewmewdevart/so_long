/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:36:43 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/06 12:36:44 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to draws the game map on screen, placing each object (walls, floors, player, exit, and collectibles) in the correct position based on their coordinates in the matrice
int	ft_map_draw(t_game_instance *game_init)
{
	int	row;
	int	column;

	row = -1;
	while (game_init->map_init.matrice[++row])
	{
		column = 0;
		while (game_init->map_init.matrice[row][column])
		{
			if (game_init->map_init.matrice[row][column] == WALL)
				ft_set(game_init, game_init->game_objs.wall, column, row);
			if (game_init->map_init.matrice[row][column] == EMPTY)
				ft_set(game_init, game_init->game_objs.floor, column, row);
			if (game_init->map_init.matrice[row][column] == PLAYER)
				ft_set(game_init, game_init->game_objs.player, column, row);
			if (game_init->map_init.matrice[row][column] == EXIT && game_init->game_data.count_collectible == 0)
				ft_set(game_init, game_init->game_objs.exit_open, column, row);
			if (game_init->map_init.matrice[row][column] == EXIT && game_init->game_data.count_collectible != 0)
				ft_set(game_init, game_init->game_objs.exit_close, column, row);
			if (game_init->map_init.matrice[row][column] == COLLECTIBLE)
				ft_set(game_init, game_init->game_objs.collectible, column, row);
			column++;
		}
	}
	return (0);
}

// Function to sets the image of an object in the corresponding cell on the game board
void	ft_set(t_game_instance *game_init, void *img, int width, int height)
{
	mlx_put_image_to_window(game_init->mlx_ptr, game_init->win_ptr, img, width * CELL_SIZE, height * CELL_SIZE);
}
