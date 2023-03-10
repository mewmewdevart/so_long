/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:16:49 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/10 20:16:52 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_initialize(void)
{
	ft_map_start_map();
	ft_map_start_data();
}

t_map	ft_map_start_map(void)
{
	t_map	map_data;

	map_data = (t_map){0};
	map_data.matrice = NULL;
	return (map_data);
}

t_map_content	ft_map_start_data(void)
{
	t_map_content	map_data;

	map_data = (t_map_content){0};
	return (map_data);
}

int	ft_read_matrice(t_map *map_data)
{
	if (ft_is_valid_map(map_data) == -1)
		return (-1);
	ft_printf("\n");
	ft_printf("%d\n", map_data->cols);
	ft_printf("%d\n", map_data->rows);
	return (1);
}
