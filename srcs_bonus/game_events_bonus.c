#include "../include/so_long_bonus.h"

// Function to sets up the game window and calls ft_map_draw to draw the game map (is the gear of the game)
void	ft_gameplay_start(t_game_instance *game_init)
{
	mlx_hook(game_init->win_ptr, 17, 0, ft_exit_program, game_init);
	mlx_hook(game_init->win_ptr, 2, (1L << 0), ft_check_keyboard, game_init);
	mlx_loop_hook(game_init->mlx_ptr, &ft_map_draw, game_init);
}

// Function to check an event handler for keyboard input during the game
int	ft_check_keyboard(int key, t_game_instance *game_init)
{
	if (key == ESC)
	{
		ft_printf("\nOh, is this game a little hard for you? :c\n");
		ft_exit_program(game_init);
	}
	else if (key == W || key == UP)
	{
		game_init->game_objs.player = game_init->game_objs.player_up;
		ft_events_pressed(game_init, 0, -1);
	}
	else if (key == A || key == LEFT)
	{
		game_init->game_objs.player = game_init->game_objs.player_left;
		ft_events_pressed(game_init, -1, 0);
	}
	else if (key == S || key == DOWN)
	{
		game_init->game_objs.player = game_init->game_objs.player_down;
		ft_events_pressed(game_init, 0, +1);
	}
	else if (key == D || key == RIGHT)
	{
		game_init->game_objs.player = game_init->game_objs.player_right;
		ft_events_pressed(game_init, +1, 0);
	}
	else if (key == RESTART)
		ft_reset_game(game_init);
	ft_print_shell(game_init);
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
	if (game_init->map_init.matrice[game_init->positions_init.player_row + row][game_init->positions_init.player_col + column] == EMPTY)
	{
		game_init->map_init.matrice[game_init->positions_init.player_row + row][game_init->positions_init.player_col + column] = PLAYER;
		game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] = EMPTY;
		game_init->game_data.count_movements++;
	}
	if (game_init->map_init.matrice[game_init->positions_init.player_row + row][game_init->positions_init.player_col + column] == COLLECTIBLE)
	{
		game_init->map_init.matrice[game_init->positions_init.player_row + row][game_init->positions_init.player_col + column] = PLAYER;
		game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] = EMPTY;
		game_init->game_data.count_collectible--;
		game_init->game_data.count_movements++;
	}
	if (game_init->map_init.matrice[game_init->positions_init.player_row + row][game_init->positions_init.player_col + column] == ENEMY)
	{
		ft_printf("\nGame over! ");
		ft_printf("Better luck next time! Your score was [%d] moves!\n",  game_init->game_data.count_movements);
		ft_exit_program(game_init);
	}
	if (game_init->map_init.matrice[game_init->positions_init.player_row + row][game_init->positions_init.player_col + column] == EXIT && game_init->game_data.count_collectible == 0)
	{
		game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] = EMPTY;
		game_init->game_data.count_movements++;
		ft_printf("\nCongratulations! You have found all the stars in the game.\n");
		ft_printf("You made %d moves. Is that the best you can do?\n", game_init->game_data.count_movements);
		ft_exit_program(game_init);
	}
}

// Function to finds the player position and performs actions like moving the player or removing a collectible based on the block they're trying to move to, after the player presses a key
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
