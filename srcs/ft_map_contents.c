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

/*
int ft_map_behaviors(char *map)
{
    ft_map_start();
    ft_isrectangular(map);
    ft_map_composed(map);

    return (1);
}
*/
/*  FUNÇÃO PRINCIPAL QUE PRECISA SER CHAMADA DENTRO DO FT_MAPS NO FD
int ft_count_aligned(char *map, int size_content)
{
    int rows;
    int cols;
    int i;
    int j;

    j = i = 0;
    while(i < size_content)
    {
        if(map[i] == '\n')
            rows++;
        while(j < size_content)
        {
            if(map[j] == '\n')
                cols++;
            j++;
        }
        i++;
    }

    //verificar se é retangulo
    if (cols > rows)
    {
        if(ft_check_walls(map) == 1 )
            ft_map_composed(map);
    }
    else
    {
        return(-1);
        ft_error_map("aligned",61);
    }
    return(1);
}
*/

//int	ft_isrectangular(char *map, int size_content)
int	ft_isrectangular(char *map)
{
	//map[rows][cols]
	ft_printf("%s", map);
	return(1);
}

// linked list for loop
t_map_content	ft_map_composed(char *map)
{
	char *next_occurrence = map;
	t_map_content   layers;
	
	
	if (map == NULL)
	{
		layers.count_player = -1;
		return (layers);
	}

	while (next_occurrence != NULL && *next_occurrence != '\0')
	{
		if (*next_occurrence == PLAYER)
		{
			next_occurrence++;
			layers.count_player = ft_strchr_all_oc(next_occurrence, PLAYER);
			next_occurrence--;
		}
		else if (*next_occurrence == EXIT)
		{
			next_occurrence++;
			layers.count_exit = ft_strchr_all_oc(next_occurrence, EXIT);
			next_occurrence--;
		}
		else if (*next_occurrence == COLLECTIBLE)
		{
			next_occurrence++;
			layers.count_collectible = ft_strchr_all_oc(next_occurrence, COLLECTIBLE);
			next_occurrence--;
		}
		else if (*next_occurrence == WALL)
		{
			next_occurrence++;
			layers.count_wall = ft_strchr_all_oc(next_occurrence, WALL);
			next_occurrence--;
		}
		else if (*next_occurrence == EMPTY)
		{
			next_occurrence++;
			layers.count_empty = ft_strchr_all_oc(next_occurrence, EMPTY);
			next_occurrence--;
		}
		next_occurrence++;
	}
	//Armazenando os valores da leitura em uma struct
	return (layers);
}

int ft_map_composed_valid(t_map_content *map_info)
{
	if (map_info->count_player != 1 || map_info->count_exit != 1 || map_info->count_collectible < 1)
	{
		ft_error_map("content error", 61);
		return(-1);
	}
	return(1);
}

int ft_check_walls(char *map)
{
    int i;

    i = 0;
    while(map[i] != '\0')
    {
        if(map[i] == '\n')
		{
			if(map[i - 1] == WALL)
				continue;
			else
			{
				ft_error_map("map", 61);
				return(-1);
			}
		}
		i++;
	}
    ft_printf("\n É protegido por muros! %s\n", map);
    return(1);
}
