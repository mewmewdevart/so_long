/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:59:51 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 16:59:52 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// Function to starts the game instance and initializes the necessary structures
int	main(int argc, char **argv)
{
	t_game_instance	game_init;

	ft_struct_init(&game_init);
	if (argc != 2)
		ft_error_map(22);
	game_init.argc_tmp = argc;
	game_init.argv_tmp = argv;
	if (ft_open_map(argv[1], &game_init))
	{
		ft_initialize_game(&game_init);
		ft_gameplay_start(&game_init);
		mlx_loop(game_init.mlx_ptr);
	}
	else
		ft_error_map(61);
	ft_exit_program(&game_init);
	return (0);
}

// Function to initialize all structs in the game instance + malloc in objs
void	ft_struct_init(t_game_instance *game_init)
{
	t_game_objs	*objects;

	*game_init = (t_game_instance){0};
	game_init->map_init.matrice = NULL;
	game_init->mlx_ptr = NULL;
	game_init->win_ptr = NULL;
	game_init->resolutions_init.settings_name_map = NULL;
	game_init->resolutions_init.settings_name_window = NULL;
	objects = malloc(sizeof(t_game_objs));
	if (objects == NULL)
		ft_error_map(12);
	game_init->game_objs = *objects;
	free (objects);
	return ;
}
