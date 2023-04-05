/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:18:07 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/30 14:38:41 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_keyboard(int key, t_game_instance *game_init)
{
	if (key == ESC)
		ft_exit_program(game_init);
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
		ft_events_pressed(game_init, 0 , +1);
	}
	else if (key == D || key == RIGHT)
	{
		game_init->game_objs.player = game_init->game_objs.player_right;
		ft_events_pressed(game_init, +1, 0);
	}
	else if (key == RESTART)
	{
		ft_printf("Voce pressionou a tecla de restart!\n");
		ft_reset_game(game_init);
	}
	return (0);
}

int ft_exit_program(t_game_instance *game_init)
{
	ft_printf("Closing the window and program.. \n");

	ft_free_img(game_init);

	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	free(game_init->mlx_ptr);
	free(game_init->resolutions_init.settings_name_window);
	free(game_init->resolutions_init.settings_name_map);
	ft_free_map(game_init);
	exit(0);
	return (0);
}

void	ft_reset_game(t_game_instance *game_init)
{
	ft_printf("Reset the game.. \n");
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	free(game_init->mlx_ptr);
	ft_free_img(game_init);
	free(game_init->resolutions_init.settings_name_window);
	free(game_init->resolutions_init.settings_name_map);
	ft_free_map(game_init);

	main(game_init->argc_tmp, game_init->argv_tmp);
}

void	ft_gameplay_start(t_game_instance *game_init)
{
	mlx_hook(game_init->win_ptr, 17, 0, ft_exit_program, game_init);
	mlx_key_hook(game_init->win_ptr, ft_check_keyboard, game_init);
	mlx_loop_hook(game_init->mlx_ptr, &ft_map_draw, game_init);
}

void ft_events_pressed(t_game_instance *game_init, int column, int row)
{
	if (game_init->map_init.matrice[game_init->positions_init.player_row + row][game_init->positions_init.player_row + column] == EMPTY)
	{
		game_init->map_init.matrice[game_init->positions_init.player_row + row][game_init->positions_init.player_row + column] = PLAYER;
		game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_row] = EMPTY;
		game_init->game_data.count_movements++;

	}
	if (game_init->map_init.matrice[game_init->positions_init.player_row + row][game_init->positions_init.player_row + column] == COLLECTIBLE)
	{
		game_init->map_init.matrice[game_init->positions_init.player_row + row][game_init->positions_init.player_row + column] = PLAYER;
		game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_row] = EMPTY;
		game_init->game_data.count_collectible--;
		game_init->game_data.count_movements++;
	}
	if (game_init->map_init.matrice[game_init->positions_init.player_row + row][game_init->positions_init.player_row + column] == EXIT && game_init->game_data.count_collectible == 0)
	{
		game_init->map_init.matrice[game_init->positions_init.player_row + row][game_init->positions_init.player_row + column] = PLAYER;
		game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_row] = EMPTY;
		game_init->game_data.count_movements++;
		ft_printf("Congratulations!\n");
		ft_exit_program(game_init);
	}
}

void ft_locate_player(t_game_instance *game_init)
{
	int col;
	int row;

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