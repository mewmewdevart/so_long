/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:36:43 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 19:19:14 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to draws the game map on screen in the correct position
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
			ft_map_continues(game_init, column, row);
			if (game_init->map_init.matrice[row][column] == COLLECTIBLE)
				ft_set(game_init, game_init->game_objs.collectible,
					column, row);
			column++;
		}
	}
	return (0);
}

void	ft_map_continues(t_game_instance *game_init, int column, int row)
{
	if (game_init->map_init.matrice[row][column] == EXIT
		&& game_init->game_data.count_collectible == 0)
		ft_set(game_init, game_init->game_objs.exit_open, column, row);
	if (game_init->map_init.matrice[row][column] == EXIT
		&& game_init->game_data.count_collectible != 0)
		ft_set(game_init, game_init->game_objs.exit_close, column, row);
	return ;
}

// Function to sets the image the corresponding cell on the game board
void	ft_set(t_game_instance *game_init, void *img, int wid, int hgt)
{
	mlx_put_image_to_window(game_init->mlx_ptr, game_init->win_ptr,
		img, wid * CELL_SIZE, hgt * CELL_SIZE);
}
