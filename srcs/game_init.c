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

static char	*ft_get_filename_start(char *path);

void	ft_initialize_game(int argc, char **argv)
{
	t_game_instance		game_init;
	t_map_data			map_data;

	game_init.mlx_ptr = mlx_init();
	if (game_init.mlx_ptr == NULL)
		ft_error_init(38);
	if (argc != 2)
		ft_error_map(22);
	else
		map_data = ft_print_name_window(argv[1]);
	if (argv[1])
	{
		if (ft_open_map(argv[1]))
		{
			ft_printf("\n Segundo o game_init.c : O mapa está supimpa!\n");
			map_data.settings_map_width = 650;
			map_data.settings_map_height = 500;

			game_init.win_ptr = mlx_new_window(game_init.mlx_ptr, map_data.settings_map_width, map_data.settings_map_height, map_data.settings_name_window);
			if (game_init.win_ptr  == NULL)
				ft_error_init(38);

			//ft_compass_positions(map_data); //Bussola das posições
			mlx_hook(game_init.win_ptr, 17, 0, ft_close_program, &game_init);
			mlx_key_hook(game_init.win_ptr, ft_check_keyboard, &game_init);

			while (TRUE)
			{
				//Acoes do game
				mlx_loop(game_init.mlx_ptr);
			}
		}
		else
			ft_error_map(61);
	}
}

t_map_data	ft_print_name_window(char *path)
{
	t_map_data	map_settings;
	char			*filename_start;
	char			*new_name_window;
	size_t			len;

	filename_start = ft_get_filename_start(path);
	if (filename_start)
	{
		len = ft_strlen(filename_start + 1);
		map_settings.settings_name_window = ft_substr(filename_start + 1, 0, len);
		if (map_settings.settings_name_window && ft_strrchr(map_settings.settings_name_window, '.') != NULL)
			*(ft_strrchr(map_settings.settings_name_window, '.')) = '\0';
	}
	else
		map_settings.settings_name_window = ft_strdup(path);
	new_name_window = ft_strjoin(" The Blue Knight : ", map_settings.settings_name_window);
	free(map_settings.settings_name_window);
	map_settings.settings_name_window = new_name_window;
	map_settings.settings_name_map = NULL;
	return (map_settings);
}

static char	*ft_get_filename_start(char *path)
{
	char	*filename_start;
	char	*ptr_path;

	ptr_path = path + ft_strlen(path) - 1;
	filename_start = NULL;
	while (ptr_path >= path && !(*ptr_path == '/' || *ptr_path == ' '))
	{
		if (*ptr_path == '.' && !filename_start)
			filename_start = ptr_path;
		else if (*ptr_path == '_' && filename_start)
			filename_start = NULL;
		ptr_path--;
	}
	if (filename_start == NULL && (*ptr_path == '/' || *ptr_path == ' '))
		filename_start = ptr_path;
	return (filename_start);
}
