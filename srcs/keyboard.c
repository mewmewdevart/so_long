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

int	ft_check_keyboard(int key, t_game_instance *game)
{
	if (key == ESC)
	{
		ft_printf("Closing the windows and program.. \n");
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free (game->mlx_ptr);
		exit (0);
	}
	else if (key == W || key == UP)
	{
		game->compass.player_row -= 1;
		ft_printf("TECLA W OU UP\n");
		ft_printf("O Player está na linha: %d\n", game->compass.player_row);
		ft_printf("O Player está na coluna: %d\n", game->compass.player_col);
	}
	else if (key == A || key == LEFT)
	{
		game->compass.player_col -= 1;
		ft_printf("TECLA A OU LEFT\n");
		ft_printf("O Player está na linha: %d\n", game->compass.player_row);
		ft_printf("O Player está na coluna: %d\n", game->compass.player_col);
	}
	else if (key == S || key == DOWN)
	{
		game->compass.player_row += 1;
		ft_printf("TECLA S OU DOWN\n");
		ft_printf("O Player está na linha: %d\n", game->compass.player_row);
		ft_printf("O Player está na coluna: %d\n", game->compass.player_col);
	}
	else if (key == D || key == RIGHT)
	{
		game->compass.player_col += 1;
		ft_printf("TECLA D OU RIGHT\n");
		ft_printf("O Player está na linha: %d\n", game->compass.player_row);
		ft_printf("O Player está na coluna: %d\n", game->compass.player_col);
	}
	else if (key == RESTART)
	{
		ft_printf("Voce pressionou a tecla de restart!\n");
		ft_reset_game(game);
	}
	return (0);
}

int	ft_close_program(t_game_instance *game)
{
	ft_printf("Closing the windows and program.. \n");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free (game->mlx_ptr);
	exit (0);
}

void	ft_reset_game(t_game_instance *game)
{
	ft_printf("Reset the game.. \n");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free (game->mlx_ptr);
	exit (0);
}
