/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:17:56 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/23 13:17:58 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_keys(int key, t_ptr *ptr)
{
	if (key == ESC)
	{
		ft_printf("Closing the windows and program.. \n");
		mlx_destroy_window(ptr->mlx, ptr->window);
		mlx_destroy_display(ptr->mlx);
		free (ptr->mlx);
		exit (0);
	}
	else if (key == W || key == UP)
		ft_printf("TECLA W OU UP\n");
	else if (key == A || key == LEFT)
		ft_printf("TECLA A OU LEFT\n");
	else if (key == S || key == DOWN)
		ft_printf("TECLA S OU DOWN\n");
	else if (key == D || key == RIGHT)
		ft_printf("TECLA D OU RIGHT\n");
	else
		ft_printf("\nYou pressed the key: %c -- %d \n", key, key);
	return (0);
}
