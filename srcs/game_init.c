#include "../include/so_long.h"

void	ft_initialize_game(int argc, char **argv)
{
	void	*ptr_mlx;
	void	*ptr_win;
	t_game_instance			ptr;
	t_map_settings			map_settings;

	ptr.settings.width = 650;
	ptr.settings.height = 500;
	if (argc < 2)
		ft_error_map(22);
	else
		map_settings = ft_print_map_name(argv[1]);
	ptr.settings.name_window = map_settings.name_window;

	ptr_mlx = mlx_init();
	ptr_win = mlx_new_window(ptr_mlx, ptr.settings.width, ptr.settings.height, ptr.settings.name_window);

	ft_printf("Nome do mapa: %s", ptr.settings.name_window); // Apenas para visualizar no console
	if (argc != 2)
		ft_error_map(22);
	if (argv[1])
	{
		if (ft_open_map(argv[1]) == 0 || ft_open_map(argv[1]) == -1)
			ft_error_map(61);
		else
			ft_printf("\n Segundo o game_init.c : O mapa está supimpa!\n"); //calling for game actions
	}
	ptr.argc = argc;
	ptr.argv = argv;
	ptr.mlx = ptr_mlx;
	ptr.window = ptr_win;
	mlx_hook(ptr.window, 17, 0, ft_close_program, &ptr);
	mlx_key_hook(ptr.window, ft_check_keyboard, &ptr);
	mlx_loop(ptr_mlx);
}

t_map_settings	ft_print_map_name(char *path)
{
	t_map_settings	map_settings;
	char			*p;
	char			*filename_start;
	char			*new_name_window;
    size_t          len;

	p = path + ft_strlen(path) - 1;
	filename_start = NULL;
	while (p >= path && *p != '/' && *p != ' ')
	{
		if (*p == '.'  && *p == '_' && !filename_start)
			filename_start = p;
		p--;
	}
	if (p >= path)
		filename_start = p;
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
