/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:18:07 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/10 20:18:08 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_keyboard(int key, t_game_instance *game_init)
{
	if (key == ESC)
		ft_exit_program(game_init);
	else if (key == W || key == UP)
	{
		game_init->positions_init.player_row--;
		//ft_player_up(game_init);
	}
	else if (key == A || key == LEFT)
	{
		game_init->positions_init.player_col--;
		//ft_player_left(game_init);
	}
	else if (key == S || key == DOWN)
	{
		game_init->positions_init.player_row++;
		//ft_player_down(game_init);
	}
	else if (key == D || key == RIGHT)
	{
		game_init->positions_init.player_col++;
		//ft_player_right(game_init);
	}
	else if (key == RESTART)
	{
		ft_printf("Voce pressionou a tecla de restart!\n");
		//ft_reset_game(game_init);
	}
	return (0);
}

int ft_exit_program(t_game_instance *game_init)
{
	ft_printf("Closing the window and program.. \n");
	//ft_free_img(game_init);
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	ft_free_map(game_init);
	exit(0);
}

void	ft_reset_game(t_game_instance *game_init) // Um dia
{
	ft_printf("Reset the game.. \n");
	mlx_destroy_display(game_init->mlx_ptr);
	ft_free_map(game_init);
	exit (0);
}
