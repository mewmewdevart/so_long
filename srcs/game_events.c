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
		game_init->positions_init.player_row--;
		ft_printf("TECLA W OU UP\n");
<<<<<<< HEAD
		ft_player_up(game_init);
=======
		//ft_player_up(game_init);
>>>>>>> 0ec802e (fix reading errors and memory (valgrind))
	}
	else if (key == A || key == LEFT)
	{
		game_init->positions_init.player_col--;
		ft_printf("TECLA A OU LEFT\n");
<<<<<<< HEAD
		ft_player_left(game_init);
=======
		//ft_player_left(game_init);
>>>>>>> 0ec802e (fix reading errors and memory (valgrind))
	}
	else if (key == S || key == DOWN)
	{
		game_init->positions_init.player_row++;
		ft_printf("TECLA S OU DOWN\n");
<<<<<<< HEAD
		ft_player_down(game_init);
=======
		//ft_player_down(game_init);
>>>>>>> 0ec802e (fix reading errors and memory (valgrind))
	}
	else if (key == D || key == RIGHT)
	{
		game_init->positions_init.player_col++;
		ft_printf("TECLA D OU RIGHT\n");
<<<<<<< HEAD
		ft_player_right(game_init);
=======
		//ft_player_right(game_init);
>>>>>>> 0ec802e (fix reading errors and memory (valgrind))
	}
	else if (key == RESTART)
	{
		ft_printf("Voce pressionou a tecla de restart!\n");
		ft_reset_game(game_init);
	}
	return (0);
}

	//ft_free_img(game_init);

int ft_exit_program(t_game_instance *game_init)
{
	ft_printf("Closing the window and program.. \n");
<<<<<<< HEAD
	ft_free_img(game_init);
=======
>>>>>>> 0ec802e (fix reading errors and memory (valgrind))
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	free(game_init->mlx_ptr);

	free(game_init->resolutions_init.settings_name_window);
	free(game_init->resolutions_init.settings_name_map);

	ft_free_map(game_init);
	free(game_init->mlx_ptr);
	exit(0);
	return (0);
}

void	ft_reset_game(t_game_instance *game_init) // Um dia
{
	ft_printf("Reset the game.. \n");
<<<<<<< HEAD
	ft_free_img(game_init);
=======
>>>>>>> 0ec802e (fix reading errors and memory (valgrind))
	mlx_destroy_window(game_init->mlx_ptr, game_init->win_ptr);
	mlx_destroy_display(game_init->mlx_ptr);
	free(game_init->mlx_ptr);

	free(game_init->resolutions_init.settings_name_window);
	free(game_init->resolutions_init.settings_name_map);

	ft_free_map(game_init);
<<<<<<< HEAD
	free(game_init->mlx_ptr);
=======
>>>>>>> 0ec802e (fix reading errors and memory (valgrind))
	exit(0);
}

void	ft_gameplay_start(t_game_instance *game_init)
{
	mlx_hook(game_init->win_ptr, 17, 0, ft_exit_program, game_init);
	mlx_key_hook(game_init->win_ptr, ft_check_keyboard, game_init);
	mlx_hook(game_init->win_ptr, 9, 1L << 21, ft_show_game, game_init);
}



/*
int ft_check_moves(t_game_instance *game_init)
{
    char *movements;

    mlx_string_put(game_init->mlx_ptr, game_init->win_ptr, 12, 16, 0x0100ff00, "Moves: ");
	movements = ft_itoa(game_init->game_data.count_movements);
   	mlx_string_put(game_init->mlx_ptr, game_init->win_ptr,60, 16, 0x0100ff00, movements);
    free (movements);
    return(0);
}*/