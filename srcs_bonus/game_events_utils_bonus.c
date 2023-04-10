/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:52:31 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 19:25:58 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to check an event handler for keyboard input during the game
int	ft_check_keyboard(int key, t_game_instance *game_init)
{
	ft_non_special(key, game_init);
	if (key == W || key == UP)
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
	return (0);
}

// Just a to be continue for keyboard 
int	ft_non_special(int key, t_game_instance *game_init)
{
	if (key == ESC)
	{
		ft_printf("\nOh, is this game a little hard for you? :c\n");
		ft_exit_program(game_init);
	}
	else if (key == RESTART)
		ft_reset_game(game_init);
	return (0);
}
