/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:18:07 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 19:18:59 by larcrist         ###   ########.fr       */
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

// Function to prints the current number of movements on the terminal shell
//	but only if it has changed since the last time it was called
void	ft_print_shell(t_game_instance *game_init)
{
	static int	previous_count_movements = -1;
	int			current_count_movements;

	current_count_movements = game_init->game_data.count_movements;
	if (current_count_movements != previous_count_movements)
	{
		ft_printf("You moved %d times.\n", current_count_movements);
		previous_count_movements = current_count_movements;
	}
}

// Function to takes a keyboard input and performs corresponding actions,
//			such as moving the player character or resetting the game
//							(+ call for function print in the shell)
void	ft_events_pressed(t_game_instance *game_init, int column, int row)
{
	ft_locate_player(game_init);
	if (game_init->map_init.matrice[game_init->positions_init.player_row + row]
		[game_init->positions_init.player_col + column] == EMPTY)
	{
		game_init->map_init.matrice[game_init->positions_init.player_row + row]
		[game_init->positions_init.player_col + column] = PLAYER;
		game_init->map_init.matrice[game_init->positions_init.player_row]
		[game_init->positions_init.player_col] = EMPTY;
		game_init->game_data.count_movements++;
	}
	if (game_init->map_init.matrice[game_init->positions_init.player_row + row]
		[game_init->positions_init.player_col + column] == COLLECTIBLE)
	{
		game_init->map_init.matrice[game_init->positions_init.player_row + row]
		[game_init->positions_init.player_col + column] = PLAYER;
		game_init->map_init.matrice[game_init->positions_init.player_row]
		[game_init->positions_init.player_col] = EMPTY;
		game_init->game_data.count_collectible--;
		game_init->game_data.count_movements++;
	}
	ft_press_continue(game_init, column, row);
}

void	ft_press_continue(t_game_instance *game_init, int column, int row)
{
	if (game_init->map_init.matrice[game_init->positions_init.player_row + row]
		[game_init->positions_init.player_col + column] == EXIT
		&& game_init->game_data.count_collectible == 0)
	{
		game_init->map_init.matrice[game_init->positions_init.player_row]
		[game_init->positions_init.player_col] = EMPTY;
		game_init->game_data.count_movements++;
		ft_printf("Nice! You have found all the stars in the game.\n");
		ft_printf("You made %d moves. Is that the best you can do?\n",
			game_init->game_data.count_movements);
		ft_exit_program(game_init);
	}
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
