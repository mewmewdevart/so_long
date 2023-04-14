/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:18:07 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/14 12:59:40 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to sets up the game window and calls ft_map_draw 
//		to draw the game map (is the gear of the game)
void	ft_gameplay_start(t_game_instance *game_init)
{
	mlx_hook(game_init->win_ptr, 17, 0, ft_exit_program, game_init);
	mlx_hook(game_init->win_ptr, 2, (1L << 0), ft_check_keyboard, game_init);
	mlx_loop_hook(game_init->mlx_ptr, &ft_map_draw, game_init);
}

// Function to prints the current number of movements on the terminal
int	ft_print_shell(t_game_instance *game_init)
{
	static int	previous_count_movements = -1;
	int			current_count_movements;

	current_count_movements = game_init->game_data.count_movements;
	if (current_count_movements != previous_count_movements)
	{
		ft_printf("You moved %d times.\n", current_count_movements);
		previous_count_movements = current_count_movements;
	}
	return (1);
}

// Function to takes a keyboard input and performs corresponding actions
int	ft_events_pressed(t_game_instance *game_init, int column, int row)
{
	int	new_row;
	int	new_col;
	int	current_tile;

	ft_locate_player(game_init);
	new_row = game_init->positions_init.player_row + row;
	new_col = game_init->positions_init.player_col + column;
	current_tile = game_init->map_init.matrice[new_row][new_col];
	if (current_tile == EMPTY || current_tile == COLLECTIBLE)
	{
		game_init->map_init.matrice[new_row][new_col] = PLAYER;
		game_init->map_init.matrice[game_init->positions_init.player_row]
		[game_init->positions_init.player_col] = EMPTY;
		game_init->positions_init.player_row = new_row;
		game_init->positions_init.player_col = new_col;
		if (current_tile == COLLECTIBLE)
			game_init->game_data.count_collectible--;
		game_init->game_data.count_movements++;
	}
	else if (current_tile == EXIT
		&& game_init->game_data.count_collectible == 0)
		ft_win(game_init);
	return (ft_print_shell(game_init));
}

// Function to finds the player position and performs actions like moving the
//	player or removing a collectible based on the block they're trying to move
// to after the player presses a key
void	ft_locate_player(t_game_instance *game_init)
{
	int	col;
	int	row;

	row = 0;
	while (game_init->map_init.matrice[row] != NULL)
	{
		col = 0;
		while (game_init->map_init.matrice[row][col] != '\0')
		{
			if (game_init->map_init.matrice[row][col] == PLAYER)
			{
				game_init->positions_init.player_row = row;
				game_init->positions_init.player_col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}
