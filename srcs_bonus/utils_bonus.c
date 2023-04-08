#include "../include/so_long_bonus.h"

static char	*ft_get_filename_start(char *path);

// Function to compares two strings character by character and returns the difference between the first two non-matching characters (in ASCII value)
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// Function to take the path, filter it and put in the game window
void	ft_print_name_window(t_game_instance *game_init, char *path)
{
	char	*filename_start;
	char	*new_name_window;
	size_t	len;

	filename_start = ft_get_filename_start(path);
	if (filename_start)
	{
		len = ft_strlen(filename_start + 1);
		game_init->resolutions_init.settings_name_window = ft_substr(filename_start + 1, 0, len);
		if (game_init->resolutions_init.settings_name_window && ft_strrchr(game_init->resolutions_init.settings_name_window, '.') != NULL)
			*(ft_strrchr(game_init->resolutions_init.settings_name_window, '.')) = '\0';
	}
	else
		game_init->resolutions_init.settings_name_window = ft_strdup(path);
	new_name_window = ft_strjoin(" The Blue Knight : ", game_init->resolutions_init.settings_name_window);
	free(game_init->resolutions_init.settings_name_window);
	game_init->resolutions_init.settings_name_window = new_name_window;
	game_init->resolutions_init.settings_name_map = NULL;
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
