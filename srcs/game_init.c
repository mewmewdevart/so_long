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
	t_game_instance			game_init;
	t_map_settings			map_settings;

	
	game_init.mlx = mlx_init();
	if (game_init.mlx == NULL)
		ft_error_init (38);
	if (argc != 2)
		ft_error_map(22);
	else
		map_settings = ft_print_name_window(argv[1]);
	if (argv[1])
	{
		if (ft_open_map(argv[1]))
		{
			ft_printf("\n Segundo o game_init.c : O mapa está supimpa!\n"); //calling for game action

			game_init.settings.name_window = map_settings.name_window;
			game_init.settings.width = 650; //necessario fazer o calculo do tamanho do mapa, dos sprites e de como isso afetara a tela
			game_init.settings.height = 500;

			game_init.window  = mlx_new_window(game_init.mlx, game_init.settings.width, game_init.settings.height, game_init.settings.name_window);
			if (game_init.window  == NULL)
				ft_error_init (38);
			mlx_hook(game_init.window, 17, 0, ft_close_program, &game_init);
			mlx_key_hook(game_init.window, ft_check_keyboard, &game_init);
			mlx_loop(game_init.mlx);
			while (TRUE)
			{
				//Acoes do game
				ft_compass_positions(game_init.map_data); //Bussola das posições
				mlx_loop(game_init.mlx);
			}
		}
		else
			ft_error_map(61); //need to be free
	}
}

t_map_settings	ft_print_name_window(char *path)
{
	t_map_settings	map_settings;
	char			*filename_start;
	char			*new_name_window;
	size_t			len;

	filename_start = ft_get_filename_start(path);
	if (filename_start)
	{
		len = ft_strlen(filename_start + 1);
		map_settings.name_window = ft_substr(filename_start + 1, 0, len);
		if (map_settings.name_window && ft_strrchr(map_settings.name_window, '.') != NULL)
			*(ft_strrchr(map_settings.name_window, '.')) = '\0';
	}
	else
		map_settings.name_window = ft_strdup(path);
	new_name_window = ft_strjoin(" The Blue Knight : ", map_settings.name_window);
	free(map_settings.name_window);
	map_settings.name_window = new_name_window;
	map_settings.map_name = NULL;
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
