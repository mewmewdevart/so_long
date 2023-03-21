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

void free_map(t_map_data *data)
{
    int i;

    i = 0;
    if (data == NULL)
        return;
    while (i < data->rows)
    {
        free(data->matrice[i]);
        i++;
    }
    free(data->matrice);
    data->matrice = NULL;
    free(data);
}
