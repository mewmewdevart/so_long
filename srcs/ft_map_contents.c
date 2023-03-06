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

int ft_read_map(char *map)
{
	t_size_map map_size;
	//t_map_content map_data = ft_map_start();
	int size;
	//int ret;

	size = ft_strlen(map);
	map_size.matrice = (char *)malloc(sizeof(char) * (size + 1));
	if (!map_size.matrice)
	{
        ft_error_map("Falha ao mallocar memoria", 1);
        return (-1);
    }
	ft_strlcpy(map_size.matrice, map, size + 1);
	if (ft_count_cols_rows(map_size.matrice, &map_size) == -1)
	{
        free(map_size.matrice);
        return (-1);
    }
	/*
	ft_map_composed(map);
    ret = ft_map_composed_valid(&map_data);
    if (ret == -1)
	{	
		return (-1);
	}*/
	//ft_printf("Rows: %d, Cols: %d, matrice: %s\n", map_size.rows, map_size.cols, map_size.matrice);
	ft_printf("%s", map);
	free(map_size.matrice);
	return(1);
}

int	ft_count_cols_rows(char *map, t_size_map *map_size)
{
	int	i;
	int	count_cols;
    int line_number;

	i = 0;
	count_cols = 0;
	map_size->rows = 0;
	map_size->cols = 0;
    line_number = 1;
	while(map[i] != '\0')
	{
		if(map[i] == '\n')
			count_cols++;
		if(map[i] == '\n')
		{
			map_size->rows++;
			if (map_size->cols  == 0)
				map_size->cols  = count_cols;
			else if(count_cols != map_size->cols )
			{
				ft_error_map("Invalid map!", 61);
				return(-1);
			}
			count_cols = 0;
            line_number++;
		}
		i++;
	}
	if (count_cols > 0)
	{
		map_size->rows++;
		if (map_size->cols  == 0)
			map_size->cols  = count_cols;
		else if (count_cols != map_size->cols)
		{
			ft_printf("Error: o número de colunas na linha %d é diferente das outras linhas.\n", line_number);
			ft_error_map("Invalid map!", 61);
			return(-1);
		}
	}
	if (map_size->rows > map_size->cols )
	{
		ft_printf("Error: a string não forma um retângulo.\n");
		ft_error_map("Invalid map!", 61);
		return(-1);
	}
	return(1);
}



/*
//Checks if the map has the main elements to be a valid map

//Checks if the map is closed by walls on its border : need one revision
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
				ft_error_map("Invalid map!", 61);
				return(-1);
			}
		}
		i++;
	}
	ft_printf("\n É protegido por muros! %s\n", map);
	return(1);
}
*/