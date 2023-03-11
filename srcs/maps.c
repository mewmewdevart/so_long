/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:11:13 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/10 20:11:14 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Open the file and storage the content in one struct
int	ft_open_map(char *map)
{
	int		fd;
	t_map	map_data;
	t_map_content data;

	ft_initialize_map_data(&map_data, &data);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (!ft_map_extension(map))
	{
		close(fd);
		return (0);
	}
	if (!ft_read_map(fd, &map_data))
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (!ft_is_valid_map(&map_data))
	{
		free(map_data.matrice);
		return (0);
	}
	free(map_data.matrice);
	return (1);
}

int	ft_read_map(int fd, t_map *map_data)
{
	int		bytes_read;
	int		total_size;
	char	buffer[BUFFER_SIZE];

	bytes_read = 0;
	total_size = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		total_size += bytes_read;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		ft_printf("%s", buffer); //apenas para debugar
	}
	map_data->size = total_size;
	map_data->matrice = (char *)malloc(sizeof(char) * (total_size + 1));
	if (!map_data->matrice)
		return (0);
	bytes_read = read(fd, map_data->matrice, total_size);
	if (bytes_read == 0)
	{
		free(map_data->matrice);
		return (0);
	}
	map_data->matrice[total_size] = '\0';
	return (1);
}
