/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:31:52 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/06 16:31:53 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_initialize_map_data(t_map_data *map, t_map_objects_counts *data)
{
	*map = ft_initialize_map();
	*data = ft_initialize_data();
}

t_map_data	ft_initialize_map(void)
{
	t_map_data	map_data;

	map_data = (t_map_data){0};
	map_data.matrice = NULL;
	return (map_data);
}

t_map_objects_counts	ft_initialize_data(void)
{
	t_map_objects_counts	value_map;

	value_map = (t_map_objects_counts){0};
	return (value_map);
}

t_compass	ft_initialize_compass(void)
{
	t_compass	compass;

	compass = (t_compass){0};
	return (compass);
}