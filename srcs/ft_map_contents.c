/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_contents.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:38:36 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/26 13:31:51 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_count_rows(char *map, int size_content)
{
	int rows;
	int i;

	i = 0;
	rows = 0;
	while(i < size_content)
	{
		if(map[i] == '\n')
			rows++;
		i++;
	}
	return(rows);
}

int	ft_count_cols(char *map, int size_content)
{
	int cols;
	int j;

	j = 0;
	cols = 0;
	while(j < size_content)
	{
		if(map[j] == '\n')
			break;
		cols++;
		j++;
	}
	return(cols);
}

//int	ft_isrectangular(char *map, int size_content)
int	ft_isrectangular(char *map)
{
	//map[rows][cols]
	ft_printf("%s", map);
	return(1);
}

t_map_content	ft_map_composed(char *map)
{
	t_map_content map_info;
	char *next_occurrence = map;

	map_info.count_player = 0;
	map_info.count_exit = 0;
	map_info.count_collectible = 0;
	map_info.count_wall = 0;
	map_info.count_empty = 0;

	if (map == NULL)
	{
		map_info.count_player = -1;
		return (map_info);
	}

	while (next_occurrence != NULL && *next_occurrence != '\0')
	{
		if (*next_occurrence == PLAYER)
		{
			next_occurrence++;
			map_info.count_player = ft_strchr_all_oc(next_occurrence, PLAYER);
			next_occurrence--;
		}
		else if (*next_occurrence == EXIT)
		{
			next_occurrence++;
			map_info.count_exit = ft_strchr_all_oc(next_occurrence, EXIT);
			next_occurrence--;
		}
		else if (*next_occurrence == COLLECTIBLE)
		{
			next_occurrence++;
			map_info.count_collectible = ft_strchr_all_oc(next_occurrence, COLLECTIBLE);
			next_occurrence--;
		}
		else if (*next_occurrence == WALL)
		{
			next_occurrence++;
			map_info.count_wall = ft_strchr_all_oc(next_occurrence, WALL);
			next_occurrence--;
		}
		else if (*next_occurrence == EMPTY)
		{
			next_occurrence++;
			map_info.count_empty = ft_strchr_all_oc(next_occurrence, EMPTY);
			next_occurrence--;
		}
		next_occurrence++;
	}
	//Armazenando os valores da leitura em uma struct
	return (map_info);
}

int ft_map_composed_valid(t_map_content *map_info)
{
	if (map_info->count_player != 1 || map_info->count_exit != 1 || map_info->count_collectible < 1)
	{
		ft_error_map("content error", 61);
		return(-1);
	}
	return(0);
}