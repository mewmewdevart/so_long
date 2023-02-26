/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:47:49 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/25 20:20:40 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//function to open the map
int	ft_map_open(char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_error_map(map, 5);
		return (-1);
	}
	if (ft_map_extension(map) == -1)
	{
		close (fd);
		return (-1);
	}
	line = "";
    while (line != NULL)
    {
        line = get_next_line(fd);
        ft_map_composed(line);
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

//function to check the content of map
int	ft_map_composed(char *map)
{
	int count_player;
    int count_exit;
    int count_collectible;
    int count_wall;
    int count_empty;

    count_player = 0;
    count_exit = 0;
    count_collectible = 0;
    count_wall = 0;
    count_empty = 0;

	if (map == NULL)
		return(0);
    while (*map != '\0')
	{
        if (*map  == PLAYER)
            count_player++;
        else if (*map == EXIT)
            count_exit++;
        else if (*map  == COLLECTIBLE)
            count_collectible++;
        else if (*map  == WALL)
            count_wall++;
        else if (*map  == EMPTY )
            count_empty++;
        map++;
    }
	if (count_player > 0)
		ft_printf("Count Player: %d\n", count_player);
	if (count_exit > 0)
		ft_printf("Count Exit: %d\n", count_exit);
	if (count_collectible > 0)
		ft_printf("Count Collectible: %d\n", count_collectible);
	if (count_wall > 0)
		ft_printf("Count Wall: %d\n", count_wall);
	if (count_empty > 0)
		ft_printf("Count Empty: %d\n", count_empty);
	ft_printf("\n");
	return (0);
}
/* function to read if the map have walls etc...
int	ft_map_composed(char *map)
{
    int count_player;
    int count_exit;
    int count_collectible;
    int count_wall;
    int count_empty;

    count_player = 0;
    count_exit = 0;
    count_collectible = 0;
    count_wall = 0;
    count_empty = 0;

    if (map == NULL)
		return(0);
	
	count_player += ft_strchr_all_oc(map, PLAYER);
    count_exit += ft_strchr_all_oc(map, EXIT);
    count_collectible += ft_strchr_all_oc(map, COLLECTIBLE);
    count_wall += ft_strchr_all_oc(map, WALL);
    count_empty += ft_strchr_all_oc(map, EMPTY);

	if (count_player > 0)
		ft_printf("Count Player: %d\n", count_player);
	if (count_exit > 0)
		ft_printf("Count Exit: %d\n", count_exit);
	if (count_collectible > 0)
		ft_printf("Count Collectible: %d\n", count_collectible);
	if (count_wall > 0)
		ft_printf("Count Wall: %d\n", count_wall);
	if (count_empty > 0)
		ft_printf("Count Empty: %d\n", count_empty);
	ft_printf("\n");

	return (0);
}
*/