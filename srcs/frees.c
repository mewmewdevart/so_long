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

void ft_free_map(t_game_instance *game_init)
{
    int i;

    if (game_init->map_init.matrice)
    {
        i = 0;
        while (game_init->map_init.matrice[i])
        {
            free(game_init->map_init.matrice[i]);
            i++;
        }
        free(game_init->map_init.matrice);
        game_init->map_init.matrice = NULL;
    }
    free(game_init);
}
/* 
void	ft_free_map(t_game_instance **game_init)
{
    int		i;

    i = 0;
    if (*game_init == NULL)
        return ;
    while (i < (*game_init)->map_init.rows_matrice)
    {
        free((*game_init)->map_init.matrice[i]);
        (*game_init)->map_init.matrice[i] = NULL;
        ft_printf("Estou dentro do arquivo free.c : %d\n", i);
        i++;
    }
    free((*game_init)->map_init.matrice);
    (*game_init)->map_init.matrice = NULL;
    free(*game_init);
    *game_init = NULL;
}
*/
