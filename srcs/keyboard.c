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
	{
		ft_printf("Closing the windows and program.. \n");
		mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
		mlx_destroy_display(game_init->mlx_ptr);
		free (game_init->mlx_ptr);
		free_map(&(game_init->map_init));
		exit (0);
	}
	else if (key == W || key == UP)
	{
		game_init->compass.player_row -= 1;
		ft_printf("TECLA W OU UP\n");
		ft_printf("O Player está na linha: %d\n", game_init->compass.player_row);
		ft_printf("O Player está na coluna: %d\n", game_init->compass.player_col);
	}
	else if (key == A || key == LEFT)
	{
		game_init->compass.player_col -= 1;
		ft_printf("TECLA A OU LEFT\n");
		ft_printf("O Player está na linha: %d\n", game_init->compass.player_row);
		ft_printf("O Player está na coluna: %d\n", game_init->compass.player_col);
	}
	else if (key == S || key == DOWN)
	{
		game_init->compass.player_row += 1;
		ft_printf("TECLA S OU DOWN\n");
		ft_printf("O Player está na linha: %d\n", game_init->compass.player_row);
		ft_printf("O Player está na coluna: %d\n", game_init->compass.player_col);
	}
	else if (key == D || key == RIGHT)
	{
		game_init->compass.player_col += 1;
		ft_printf("TECLA D OU RIGHT\n");
		ft_printf("O Player está na linha: %d\n", game_init->compass.player_row);
		ft_printf("O Player está na coluna: %d\n", game_init->compass.player_col);
	}
	else if (key == RESTART)
	{
		ft_printf("Voce pressionou a tecla de restart!\n");
		ft_reset_game(game_init);
	}
	return (0);
}

int	ft_close_program (t_game_instance *game_init)
{
	ft_printf("Closing the windows and program.. \n");
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	free (game_init->mlx_ptr);
	free_map(&(game_init->map_init));
	exit (0);
}

void	ft_reset_game(t_game_instance *game_init) // Um dia
{
	ft_printf("Reset the game.. \n");
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	free (game_init->mlx_ptr);
	exit (0);
}
