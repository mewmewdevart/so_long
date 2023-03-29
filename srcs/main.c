/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:18:24 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/10 20:18:25 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game_instance game_init;

	game_init = (t_game_instance){0};
	game_init.map_init.matrice = NULL;

	if (argc != 2)
		ft_error_map(22);
	else
		ft_print_name_window(&game_init, argv[1]);
	if (ft_open_map(argv[1], &game_init))
	{
		ft_initialize_game(&game_init);
		//ft_gameplay_start(&game_init);
		//mlx_loop(game_init.mlx_ptr);
	}
	else
		ft_error_map(61);

	return (0);
}