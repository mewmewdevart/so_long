/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:47:49 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/21 14:47:51 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//function to open the map
int	ft_map_open(char *map)
{
	int fd;
	char *line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_error(map, 5);
		return(-1);
	}
	if (ft_map_extension(map) == -1)
	{

		close(fd);
		return (-1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		//ft_map_composed(char *map)
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

//function to check the extension is .ber
int	ft_map_extension(char *map)
{
	char *extension;
	char *file_extension;
	static int file_count = 0;
	const int max_files = 1;

	extension = ".ber";
	file_extension = ft_strrchr(map, '.');
	if (map[ft_strlen(map) - 1] == '/')
	{
		ft_error(map, 21);
		return (-1);
	}
	else if (file_extension && ft_strcmp(file_extension, extension) == 0)
	{
		if (file_count >= max_files)
		{
			ft_error(map, 24);
			return (-1);
		}
		file_count++;
		ft_printf("It is a good extension!\n");
	}
	else
	{
		ft_error(map, 22);
	return (-1);
	}
	return (1);
}

//function to read if the map have walls etc...
int	ft_map_composed(char *map)
{
	ft_printf("%s", map);
	return(0);
}
