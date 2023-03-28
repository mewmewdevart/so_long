/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:06:23 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/19 15:06:25 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_initialize_game(int argc, char **argv)
{
	t_game_instance	game_init;
	t_map_data		map_data;

	map_data = (t_map_data){0};
	game_init.mlx_ptr = mlx_init();
	if (game_init.mlx_ptr == NULL)
		ft_error_init(38);
	if (argc != 2)
		ft_error_map(22);
	else if (argv[1] != NULL)
	{
		if (ft_open_map(argv[1], &map_data))
		{
			ft_printf("\n Segundo o game_init.c : O mapa está supimpa!\n");
			ft_printf("Width: %d e Height: %d\n", map_data.resolutions.settings_map_width, map_data.resolutions.settings_map_height);

			// Inicialização para chamar a resolução da tela
			game_init.map_init = map_data;
			game_init.win_ptr = mlx_new_window(game_init.mlx_ptr, map_data.resolutions.settings_map_width*CELL_SIZE, map_data.resolutions.settings_map_height*CELL_SIZE, "The Blue Knight");
			if (game_init.win_ptr == NULL)
				ft_error_init(38);

			mlx_hook(game_init.win_ptr, 17, 0, ft_close_program, &game_init);
			mlx_key_hook(game_init.win_ptr, ft_check_keyboard, &game_init);

			if (mlx_loop(game_init.mlx_ptr) < 0)
				ft_error_init(38);
		}
		else
			ft_error_map(61);
	}
}
