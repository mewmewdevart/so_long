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
	//ft_positions_player(game_init);
	if (key == ESC)
	{
		ft_printf("Closing the windows and program.. \n");
		mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
		mlx_destroy_display(game_init->mlx_ptr);
		ft_free_map(game_init);
		exit (0);
	}
	else if (key == W || key == UP)
	{
		game_init->positions_init.player_row--;
		ft_printf("TECLA W OU UP\n");
	}
	else if (key == A || key == LEFT)
	{
		game_init->positions_init.player_col--;
		ft_printf("TECLA A OU LEFT\n");
	}
	else if (key == S || key == DOWN)
	{
		game_init->positions_init.player_row++;
		ft_printf("TECLA S OU DOWN\n");
	}
	else if (key == D || key == RIGHT)
	{
		game_init->positions_init.player_col++;
		ft_printf("TECLA D OU RIGHT\n");
	}
	else if (key == RESTART)
	{
		ft_printf("Voce pressionou a tecla de restart!\n");
		ft_reset_game(game_init);
	}

	// Atualizar a posição do jogador com base na tecla pressionada
	//ft_update_player_position(game_init);
	return (0);
}

int	ft_close_program (t_game_instance *game_init)
{
	ft_printf("Closing the windows and program.. \n");
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	ft_free_map(game_init);
	exit (0);
}

void	ft_reset_game(t_game_instance *game_init) // Um dia
{
	ft_printf("Reset the game.. \n");
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	ft_free_map(game_init);
	exit (0);
}
