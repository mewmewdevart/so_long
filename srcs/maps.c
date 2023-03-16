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
	int			fd;
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
	char	*buffer;
	int		bytes_read;
	int		total_size;
	char	*temp;

	total_size = 0;
	map_data->matrice = ft_calloc(1, sizeof(char *));
	map_data->matrice[0] = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || !map_data->matrice)
		return (0);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		temp = ft_strjoin(map_data->matrice[0], buffer);
		if (!temp)
			return (0);
		free(map_data->matrice[0]);
		map_data->matrice[0] = temp;
		total_size += bytes_read;
	}
	free(buffer);
	ft_map_dimensions(map_data);
	if (map_data->matrice[0] == NULL || bytes_read == -1 || !ft_is_valid_map(map_data))
		return (0);
	return (1);
}

void ft_map_dimensions(t_map_data *map_data)
{
	int	cols;
	int	rows;

	cols = 0;
	while (map_data->matrice[0][cols] && map_data->matrice[0][cols] != '\n')
		cols++;
	map_data->cols = cols;
	rows = 1;
	while (map_data->matrice[0][cols])
	{
		if (map_data->matrice[0][cols] == '\n')
			rows++;
		cols++;
	}
	map_data->rows = rows;
	ft_printf("\nColuna : %d\n", map_data->cols);
	ft_printf("\nLinhas : %d\n", map_data->rows);
}
