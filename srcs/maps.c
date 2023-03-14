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

// Open the file and storage the content in one struct
int	ft_open_map(char *map)
{
	int		fd;
	t_map_data	map_data;

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
	free(map_data.matrice);
	return (1);
}

 // Read the file and storage the content in one struct
int	ft_read_map(int fd, t_map_data *map_data)
{
	int		bytes_read;
	int		total_size;
	char	buffer[BUFFER_SIZE];

	total_size = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		ft_printf("%s", buffer); //apenas para debugar
		total_size += bytes_read;
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
	if (ft_is_valid_map(map_data))
	{
		free(map_data->matrice);
		return (1);
	}
	if (bytes_read < total_size)
	{
		free(map_data->matrice);
		return (0);
	}
	return (1);
}
