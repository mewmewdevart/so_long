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

void	ft_initialize_map_data(t_map *map, t_map_content *data)
{
	*map = ft_initialize_map();
	*data = ft_initialize_data();
}

t_map	ft_initialize_map(void)
{
	t_map	map_data;

	map_data = (t_map){0};
	map_data.matrice = NULL;
	return (map_data);
}

t_map_content	ft_initialize_data(void)
{
	t_map_content value_map = {0, 0, 0, 0, 0};
	return (value_map);
}