/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:47:39 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/25 19:27:27 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*ft_get_filename_start(char *path);

// Compares the string pointed to, by str1 to the string pointed to by str2
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// Locate all ocurrence of the character in string
size_t	ft_strchr_all_ocurrences(char *str, char ch)
{
	size_t	count;
	char	*ptr;

	count = 0;
	ptr = ft_strchr(str, ch);
	while (ptr != NULL)
	{
		ptr = ft_strchr(ptr + 1, ch);
		count++;
	}
	return (count);
}

// Checks if each character is a white space
int	ft_is_blank(const char *str)
{
	while (*str != '\0')
	{
		if (!ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

// Clean space comparing it to the known white space characters
int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void ft_print_name_window(t_game_instance *game_init, char *path)
{
	char *filename_start;
	char *new_name_window;
	size_t len;
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
