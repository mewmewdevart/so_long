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

// Check if the all conditions is valid or not
int ft_is_valid_map(t_map_data *data)
{
	t_map_objects_counts	counts = {0};
	ft_printf("\n Eu entrei na função ft_is_valid\n");

	if(!(ft_count_map_objects(data, &counts)))
		return (0);
	if(!(ft_is_map_shape_valid(data)))
		return (0);
	if(!(ft_is_wall(data)))
		return (0);

	ft_printf("Eu sai da função ft_is_valid\n");
	return (1);
}

// Check if the map is rectangular or square
int ft_is_map_shape_valid(t_map_data *data)
{
	if (!data || data->cols <= 0 || data->rows <= 0)
		return 0;
	if (data->size == 0) 
		return 0;
	if (data->size % data->rows == 0 && data->size / data->rows == data->cols) // Verifica se a quantidade de caracteres no mapa forma um retangulo ou um quadrado
		return (1);
	return (0);
}

// Check if the map is closed/surrounded by walls
int ft_is_wall(t_map_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->rows) 
	{
		j = 0;
		while (j < data->cols)
		{
			if (i == 0 || j == 0 || i == data->rows - 1 || j == data->cols - 1) // Verifica se ta na borda da matrice
			{
				if (data->matrice[i][j] != WALL) // Verifica se a celula atual é uma parede
					return(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

// Count map content and check if it has (1)E, 1(E) and >= 1(C)
int	ft_count_map_objects(t_map_data *data, t_map_objects_counts *counts)
{
	int	i;
	int	j;

	i = 0;
	while (data->matrice[i] != NULL)
	{
		j = 0;
		while (data->matrice[i][j] != '\0')
		{
			if (data->matrice[i][j] == PLAYER)
				counts->count_player++;
			else if (data->matrice[i][j] == EXIT)
				counts->count_exit++;
			else if (data->matrice[i][j] == COLLECTIBLE)
				counts->count_collectible++;
			else if (data->matrice[i][j] == WALL)
				counts->count_wall++;
			else if (data->matrice[i][j] == EMPTY)
				counts->count_empty++;
			else if (data->matrice[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	if (!(counts->count_player == 1 && counts->count_exit == 1 && counts->count_collectible >= 1))
		return (0);
	return (1);
}
