/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_contents.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:38:36 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/28 14:51:35 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_map(char *map, t_size_map *map_size)
{
	int	char_index;

	char_index = -1;
	while (map[++char_index])
	{
		if (map[char_index] == '\n')
		{
			if (ft_check_cols(map_size, map_size->cols) == -1)
				return (-1);
			map_size->rows++;
			if (map_size->cols == 0)
				map_size->cols = char_index;
		}
	}
	if (ft_check_cols(map_size, map_size->cols) == -1)
		return (-1);
	return (1);
}

int	ft_check_cols(t_size_map *map_size, int cols_count)
{
	if (map_size->cols == 0)
		map_size->cols = cols_count;
	else if (cols_count != map_size->cols)
	{
		ft_error_map("Invalid map! The lines are not the same size.", 61);
		return (-1);
	}
	return (1);
}

int	ft_count_cols_rows(char *map, t_size_map *map_size)
{
	map_size->rows = 0;
	map_size->cols = 0;
	return (ft_check_map(map, map_size));
}

/*
int	ft_check_map(char *map, t_size_map *map_size)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i] == '\n')
		{
			if (ft_check_cols(map_size, map_size->cols) == -1)
				return (-1);
			map_size->rows++;
			if (map_size->cols == 0)
				map_size->cols = i;
			else
				map_size->cols = map_size->cols;
			if (map[i + 1] == '\0' || map[i + 1] == '\n')
			{
				ft_error_map("Invalid map! Map drawing doesn't form a rectangle.", 61);
				return (-1);
		}
		else if (map[i] != PLAYER && map[i] != WALL && map[i] != EXIT)
		{
			ft_error_map("Invalid character in the map.", 60);
			return (-1);
		}
	}
	if (ft_check_cols(map_size, map_size->cols) == -1)
		return (-1);
	return (1);
}

*/