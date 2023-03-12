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
	ft_initialize_game(argc, argv);
	return (0);
}

void	ft_initialize_game(int argc, char **argv)
{
	void	*ptr_mlx;
	void	*ptr_win;
	t_game	ptr;

	ptr.settings.width = 650;
	ptr.settings.height = 500;
	ptr.settings.name_window = "so_long"; //need to be changed witht the correct function
	ptr_mlx = mlx_init();
	ptr_win = mlx_new_window(ptr_mlx, ptr.settings.width, ptr.settings.height, ptr.settings.name_window);
	if (argc != 2)
		ft_error_map("argument", 22);
	if (argv[1])
	{
		if (ft_open_map(argv[1]) == -1)
			ft_error_map("failed to open or read map file", 23);
	}
	ptr.argc = argc;
	ptr.argv = argv;
	ptr.mlx = ptr_mlx;
	ptr.window = ptr_win;
	mlx_hook(ptr.window, 17, 0, ft_close_program, &ptr);
	mlx_key_hook(ptr.window, ft_check_keyboard, &ptr);
	mlx_loop(ptr_mlx);
}

/*
Insere dentro do main /initialize: Faz parte da chamada da função ft_print_map;
		map_settings = ft_print_map_name(argv[1]);
        ptr.settings.name_window = map_settings.name_window;

		    free(map_settings.name_window);
        free(map_settings.map_name);
*/
// Receive map path on command line and filter name only and put it in the window name
t_settings_map	ft_print_map_name(char *path)
{
	t_settings_map	map_settings;
	char			*file_extension;
	char			*p;

	p = ft_strrchr(path, '/');
	file_extension = ft_strrchr(path, '.');
	if (p != NULL)
		map_settings.name_window = ft_strdup(p + 1);
	else
		map_settings.name_window = ft_strdup(path);
	if (file_extension != NULL)
	{
		if (ft_strcmp(file_extension, ".ber") == 0)
			*file_extension = '\0';
		map_settings.map_name = ft_strdup(path);
		file_extension = ft_strrchr(map_settings.map_name, '.');
		if (ft_strcmp(file_extension, ".ber") == 0)
			*file_extension = '\0';
	}
	else
		ft_error_map("file does not have extension", 25);
	return (map_settings);
}
