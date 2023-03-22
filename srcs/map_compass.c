/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_compass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:12:52 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/22 11:12:54 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to compass all positions inside the map
t_game_compass	ft_compass_positions(t_map_data map_data)
{
	t_game_compass	compass;

	compass = ft_compass_player(&map_data, &compass);
	ft_compass_exit(&map_data, &compass);
	return (compass);
}

t_game_compass	ft_compass_player(t_map_data *map_data, t_game_compass *compass)
{
	int	i;
	int	j;

	i = 0;
	while (map_data->matrice[i] != NULL)
	{
		j = 0;
		while (map_data->matrice[i][j] != '\0')
		{
			if (map_data->matrice[i][j] == PLAYER)
			{
				compass->player_row = i;
				compass->player_col = j;
				return (*compass);
			}
			j++;
		}
		i++;
	}
	return (*compass);
}

t_game_compass	ft_compass_exit(t_map_data *map_data, t_game_compass *compass)
{
	int	i;
	int	j;

	i = 0;
	while (map_data->matrice[i] != NULL)
	{
		j = 0;
		while (map_data->matrice[i][j] != '\0')
		{
			if (map_data->matrice[i][j] == EXIT)
			{
				compass->exit_row = i;
				compass->exit_col = j;
				ft_printf("A Saida está na linha: %d\n", compass->exit_row);
				ft_printf("A Saida está na coluna: %d\n", compass->exit_col);
				return (*compass);
			}
			j++;
		}
		i++;
	}
	return (*compass);
}
