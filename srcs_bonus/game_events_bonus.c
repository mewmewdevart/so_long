/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:29:16 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 18:53:21 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// Function to sets up the game window and calls ft_map_draw to draw the game map
void	ft_gameplay_start(t_game_instance *game_init)
{
	mlx_hook(game_init->win_ptr, 17, 0, ft_exit_program, game_init);
	mlx_hook(game_init->win_ptr, 2, (1L << 0), ft_check_keyboard, game_init);
	mlx_loop_hook(game_init->mlx_ptr, &ft_gameplay_update, game_init);
}

int	ft_gameplay_update(void *param)
{
	t_game_instance	*game_init;

	game_init = (t_game_instance *)param;
	ft_enemy_events(game_init);
	ft_anim_collectable(game_init);
	ft_map_draw(game_init);
	return (0);
}

// Function to prints the current number of movements on the terminal shell, but only if the number of movements has changed since the last time it was called
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

// Function to takes a keyboard input and performs corresponding actions, such as moving the player character or resetting the game (+ call for function print in the shell)
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
	if (game_init->map_init.matrice[game_init->positions_init.player_row + row]
		[game_init->positions_init.player_col + column] == ENEMY)
	{
		ft_printf("\nGame over! ");
		ft_printf("Better luck next time! Your score was [%d] moves!\n", game_init->game_data.count_movements);
		ft_exit_program(game_init);
	}
	if (game_init->map_init.matrice[game_init->positions_init.player_row + row]
		[game_init->positions_init.player_col + column] == EXIT && game_init->game_data.count_collectible == 0)
	{
		game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] = EMPTY;
		game_init->game_data.count_movements++;
		ft_printf("\nCongratulations! You have found all the stars in the game.\n");
		ft_printf("You made %d moves. Is that the best you can do?\n", game_init->game_data.count_movements);
		ft_exit_program(game_init);
	}
}

// Function to finds the player position and performs actions like moving
// the player or removing a collectible based on the block they're 
//		trying to move to, after the player presses a key
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
