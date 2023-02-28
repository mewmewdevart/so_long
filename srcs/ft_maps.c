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
//function to open the map
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

	while ((line = get_next_line(fd)) != NULL)
	{
		if (!ft_isrectangular(line))
		{
			close(fd);
			ft_error_map(map, 61);
			free(line);
			return (-1);
		}
        //ft_count_aligned(map, count);
        //count++;
        //ft_map_behaviors(line); one function to call
        ft_map_composed(line);
		/* t_map_content map_info = ft_map_composed(line);
		ft_map_composed_valid(&map_info); */
		free(line);
	}

	close(fd);
	return (0);
}


//function to check the extension is .ber
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
		ft_printf("It is a good extension!\n");
	}
	else
	{
		ft_error_map(map, 22);
		return (-1);
	}
	return (1);
}

t_map_content   ft_map_start(void)
{
    t_map_content   layers;

    layers.count_player = 0;
    layers.count_exit = 0;
    layers.count_collectible = 0;
    layers.count_wall = 0;
    layers.count_empty = 0;

    return(layers);
}
