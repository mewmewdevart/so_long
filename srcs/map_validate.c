/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:12:31 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/10 20:12:32 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Check if the all conditions is valid or not
int	ft_is_valid_map(t_map *data)
{
	if (!ft_is_rectangular(data))
		return (0);
	if (!ft_is_wall(data))
		return (0);
	if (!ft_is_content(data))
		return (0);
	return (1);
}

//Check if the map is rectangular
int	ft_is_rectangular(t_map *data)
{
	int char_index;
	int rows = 0;
	int cols = 0;

	char_index = -1;
	while (data->matrice[++char_index])
	{
		if (data->matrice[char_index] == '\n')
		{
			if (cols == 0)
				cols = char_index;
			else if (char_index - cols != 1)
				return (0);
			rows++;
		}
	}
	if (cols == 0 || char_index - cols != 1)
		return (0);

	if (!(cols > rows))
		return (0);
	data->rows = rows;
	data->cols = cols;
	return (1);
}

//Check if the map is closed/surrounded by walls
int	ft_is_wall(t_map *data)
{
	int rows;
	int cols;
	char *matrice;
	int i;

	// Check top and bottom rows
	i = 0;
	rows = data->rows;
	cols = data->cols;
	matrice = data->matrice;
	while (i < cols)
	{
		if (matrice[i] != WALL || matrice[(rows - 1) * (cols + 1) + i] != WALL)
			return (0);
		i++;
	}
	// Check left and right columns
	i = 0;
	while (i < rows)
	{
		if (matrice[i * (cols + 1)] != WALL || matrice[(i + 1) * (cols + 1) - 2] != WALL)
			return (0);
		i++;
	}
	return (1);
}

//The map must contain 1 exit, 1 starting position and at least 1 collectible
 int	ft_is_content(t_map *data)
{
    char *str = data->matrice;
	t_map_content value_map;
    int i = 0;
    
    while(str[i] != '\0')
    {
        if (str[i] == 'P')
            value_map.count_player++;
        else if (str[i] == 'E')
            value_map.count_exit++;
        else if (str[i] == 'C')
            value_map.count_collectible++;
        i++;
    }
    if (value_map.count_player == 1 && value_map.count_exit == 1 && value_map.count_collectible >= 1)
	{
		ft_printf("\n");
		ft_printf("Count player: %d\n", value_map.count_player);
		ft_printf("Count player: %d\n", value_map.count_exit);
		ft_printf("Count player: %d\n", value_map.count_collectible);
		return(1);
	}
    else
        return(0);
}

//Check if the map have a valid .ber extension and path/
int	ft_map_extension(char *map)
{
	char		*extension;
	char		*file_extension;
	static int	file_count = 0;
	const int	max_files = 1;

	extension = ".ber";
	file_extension = ft_strrchr(map, '.');
	if (map[ft_strlen(map) - 1] == '/')
	{
		ft_error_map(map, 21);
		return (0);
	}
	else if (file_extension && ft_strcmp(file_extension, extension) == 0)
	{
		if (file_count >= max_files)
		{
			ft_error_map(map, 24);
			return (0);
		}
		file_count++;
	}
	else
		return (0);
	return (1);
}