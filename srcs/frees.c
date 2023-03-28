/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:16:52 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/19 15:16:54 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_map_data *map_data)
{
	int		i;

	i = 0;
	if (map_data == NULL)
		return ;
	while (i < map_data->rows_matrice)
	{
		free(map_data->matrice[i]);
		map_data->matrice[i] = NULL;
		ft_printf("Estou dentro do arquivo free.c : %d\n", i);
		i++;
	}
	free(map_data->matrice);
	map_data->matrice = NULL;
	map_data = NULL;
}
