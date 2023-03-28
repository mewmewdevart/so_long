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

	game_init = (t_game_instance){0};
	game_init.map_init.matrice = NULL;
 
	game_init.mlx_ptr = mlx_init();
	if (game_init.mlx_ptr == NULL)
		ft_error_init(38);
	if (argc != 2)
		ft_error_map(22);
	else if (argv[1] != NULL)
	{
		if (ft_open_map(argv[1], &game_init))
		{
			ft_printf("\n Segundo o game_init.c : O mapa está supimpa!\n");
			ft_printf("Width: %d e Height: %d\n", game_init.map_init.resolutions.settings_map_width, game_init.map_init.resolutions.settings_map_height);

			// Inicialização para chamar a resolução da tela
			//game_init.map_init = map_data;
			game_init.win_ptr = mlx_new_window(game_init.mlx_ptr, game_init.map_init.resolutions.settings_map_width*CELL_SIZE, game_init.map_init.resolutions.settings_map_height*CELL_SIZE, "The Blue Knight");
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


/*
t_game_resolutions	ft_print_name_window(char *path)
{
	t_game_resolutions	resolutions;

	char			*filename_start;
	char			*new_name_window;
	size_t			len;

	filename_start = ft_get_filename_start(path);
	if (filename_start)
	{
		len = ft_strlen(filename_start + 1);
		resolutions.settings_name_window = ft_substr(filename_start + 1, 0, len);
		if (resolutions.settings_name_window && ft_strrchr(resolutions.settings_name_window, '.') != NULL)
			*(ft_strrchr(resolutions.settings_name_window, '.')) = '\0';
	}
	else
		resolutions.settings_name_window = ft_strdup(path);
	new_name_window = ft_strjoin(" The Blue Knight : ", resolutions.settings_name_window);
	free(resolutions.settings_name_window);
	resolutions.settings_name_window = new_name_window;
	resolutions.settings_name_map = NULL;
	return (resolutions);
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
*/