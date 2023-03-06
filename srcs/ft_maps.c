/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:47:49 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/28 14:51:02 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Uses get_next_line to read the file and check the map errors
int ft_map_open(char *map)
{
    int fd;
    char *line;

    fd = open(map, O_RDONLY);
    if (fd == -1)
    {
        ft_error_map(map, 5);
        return (-1);
    }
    if (ft_map_extension(map) == -1)
    {
        close(fd);
        return (-1);
    }
    while ((line = get_next_line(fd)))
    {
        if (!ft_read_map(line))
        {
            free(line);
            close(fd);
            return (-1);
        }
        free(line);
    }
    close(fd);
    return (0);
}

//Check if the map have the correct path and .ber extension
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
		return (-1);
	}
	else if (file_extension && ft_strcmp(file_extension, extension) == 0)
	{
		if (file_count >= max_files)
		{
			ft_error_map(map, 24);
			return (-1);
		}
		file_count++;
	}
	else
	{
		ft_error_map(map, 22);
		return (-1);
	}
	return (1);
}
