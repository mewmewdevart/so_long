/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:18:24 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/30 14:43:24 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
<<<<<<< HEAD
	t_game_instance	game_init;
=======
	t_game_instance game_init;

>>>>>>> 0ec802e (fix reading errors and memory (valgrind))

	ft_struct_init(&game_init);
	if (argc != 2)
		ft_error_map(22);
	else
		ft_print_name_window(&game_init, argv[1]);
	if (ft_open_map(argv[1], &game_init))
	{
		ft_printf("PRINTANDO A MATRIZ DE DENTRO DO ft_open_map: %s\n", game_init.map_init.matrice);
		ft_initialize_game(&game_init);
		ft_gameplay_start(&game_init);
<<<<<<< HEAD
		mlx_loop(game_init.mlx_ptr);
	}
	else
		ft_error_map(61);
	return (0);
}

void	ft_struct_init(t_game_instance *game_init)
{
	*game_init = (t_game_instance){0};
	game_init->map_init.matrice = NULL;
	game_init->mlx_ptr = NULL;
	game_init->win_ptr = NULL;
	game_init->resolutions_init.settings_name_map = NULL;
	game_init->resolutions_init.settings_name_window = NULL;
	game_init->game_objs = (t_game_objs){
		.player = NULL,
		.player_left = NULL,
		.player_right = NULL,
		.player_down = NULL,
		.player_up = NULL,
		.collectible = NULL,
		.exit_on = NULL,
		.exit_off = NULL,
		.wall = NULL,
		.floor = NULL,
		.img_width = 0,
		.img_height = 0
	};
}
=======

		if (mlx_loop(game_init.mlx_ptr) < 0)
				ft_error_init(38);
	}
	else
		ft_error_map(61);

	ft_exit_program(&game_init);
	return (0);
}

 void ft_struct_init(t_game_instance *game_init)
{
    *game_init = (t_game_instance){0};
    game_init->map_init.matrice = NULL;
    game_init->mlx_ptr = NULL;
    game_init->win_ptr = NULL;
    game_init->resolutions_init.settings_name_map = NULL;
    game_init->resolutions_init.settings_name_window = NULL;
    game_init->game_objs = (t_game_objs){NULL};
	return ;
}
>>>>>>> 0ec802e (fix reading errors and memory (valgrind))
