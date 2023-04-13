/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:10:43 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 17:26:13 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_collide(t_game_instance *game_init, int row, int col, int direc)
{
	if (game_init->map_init.matrice[row][col] == PLAYER)
	{
		ft_printf("\nGame over! Your score was [%d] moves!\n",
			game_init->game_data.count_movements);
		ft_exit_program(game_init);
	}
	game_init->map_init.matrice[row]
	[game_init->positions_init.enemy_col] = EMPTY;
	game_init->map_init.matrice[row][col] = ENEMY;
	game_init->positions_init.enemy_col = col;
	game_init->positions_init.enemy_direction = direc;
}

void	ft_enemy_events(t_game_instance *game_init)
{
	int	enemy_row;
	int	enemy_col;
	int	enemy_direction;

	ft_locate_enemy(game_init);
	enemy_row = game_init->positions_init.enemy_row;
	enemy_col = game_init->positions_init.enemy_col;
	enemy_direction = game_init->positions_init.enemy_direction;
	if (enemy_direction == 1
		&& (enemy_col == game_init->map_init.cols_matrice - 2
			|| game_init->map_init.matrice[enemy_row][enemy_col + 1] != EMPTY))
	{
		enemy_direction = -1;
		enemy_col--;
	}
	else if (enemy_col == 1 || game_init->map_init.matrice[enemy_row]
		[enemy_col - 1] != EMPTY)
	{
		enemy_direction = 1;
		enemy_col++;
	}
	else
		enemy_col += enemy_direction;
	ft_collide(game_init, enemy_row, enemy_col, enemy_direction);
}

void	ft_locate_enemy(t_game_instance *game_init)
{
	int	col;
	int	row;

	row = 0;
	while (game_init->map_init.matrice[row])
	{
		col = 0;
		while (game_init->map_init.matrice[row][col])
		{
			if (game_init->map_init.matrice[row][col] == ENEMY)
			{
				game_init->positions_init.enemy_row = row;
				game_init->positions_init.enemy_col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}
