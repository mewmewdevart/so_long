/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:12:15 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/30 13:01:07 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Function to returns feedback for errors that are related to the initialization of the game
void	ft_error_init(int n)
{
	if (n == 38)
	{
		ft_printf("Error\n");
		ft_printf("%sCheck library compatibility!", COLOR_RED);
	}
	if (n == 2)
	{
		ft_printf("Error\n");
		ft_printf("%sNo such file or directory|", COLOR_RED);
	}
	exit(n);
}

// Function to returns feedback for errors that are related to the map
void	ft_error_map(int n)
{
	if (n == 21)
		ft_printf("%sError\n This is a directory. \n", COLOR_RED);
	else if (n == 22 || n == 52 || n == 59 || n == 24 || n == 5)
		ft_printf("%sError\n Usage: ./so_long <filename>.ber \n", COLOR_RED);
	else if (n == 61)
		ft_printf("%sError\n Try create one valid map! \n", COLOR_RED);
	exit(n);
}
