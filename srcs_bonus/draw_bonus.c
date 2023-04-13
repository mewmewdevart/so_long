/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:26:48 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 19:19:59 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// Function to draws the game map on screen, placing each objects 
//	in the correct position based on their coordinates in the matrice
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
			if (game_init->map_init.matrice[row][column] == EMPTY)
				ft_set(game_init, game_init->game_objs.floor, column, row);
			if (game_init->map_init.matrice[row][column] == PLAYER)
				ft_set(game_init, game_init->game_objs.player, column, row);
			if (game_init->map_init.matrice[row][column] == WALL)
				ft_draw_wall(game_init);
			ft_draw_continues(game_init, column, row);
			if (game_init->map_init.matrice[row][column] == COLLECTIBLE)
				ft_set(game_init, game_init->game_objs.collectible,
					column, row);
			column++;
		}
	}
	return (ft_player_moves(game_init));
}

void	ft_draw_continues(t_game_instance *game_init, int column, int row)
{
	if (game_init->map_init.matrice[row][column] == ENEMY)
		ft_set(game_init, game_init->game_objs.enemy, column, row);
	if (game_init->map_init.matrice[row][column] == EXIT
		&& game_init->game_data.count_collectible == 0)
		ft_set(game_init, game_init->game_objs.exit_open, column, row);
	if (game_init->map_init.matrice[row][column] == EXIT
		&& game_init->game_data.count_collectible != 0)
		ft_set(game_init, game_init->game_objs.exit_close, column, row);
	return ;
}

// Function to prints the current number of movements on the terminal shell
int	ft_player_moves(t_game_instance *game_init)
{
	char	*movements;

	mlx_string_put(game_init->mlx_ptr, game_init->win_ptr,
		12, 16, 0x00FFFFFF, "Moves: ");
	movements = ft_itoa (game_init->game_data.count_movements);
	mlx_string_put(game_init->mlx_ptr, game_init->win_ptr,
		60, 16, 0x00FFFFFF, movements);
	free(movements);
	return (0);
}

// Function to sets the image of an object in the corresponding cell
void	ft_set(t_game_instance *game_init, void *img, int wid, int hgt)
{
	mlx_put_image_to_window(game_init->mlx_ptr, game_init->win_ptr,
		img, wid * CELL_SIZE, hgt * CELL_SIZE);
}
