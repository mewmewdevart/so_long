/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:12:15 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/10 20:12:17 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_map(char *local, int n)
{
	if (n == 21)
	{
		ft_printf("%s: %s\n", local, strerror(n));
		ft_printf("This is a directory. Try to open one valid file! \n");
		exit(n);
	}
	else if (n == 22 || n == 52 || n == 59 || n == 24 || n == 5)
	{
		ft_printf("%s: %s\n", local, strerror(n));
		ft_printf("Usage: ./so.long <filename>.ber\n");
		exit(n);
	}
	else if (n == 61)
	{
		ft_printf("%s: %s\n", local, strerror(n));
		ft_printf("No data available! Try create one valid map!\n");
		exit(n);
	}
	ft_printf("%s: %s\n", local, strerror(n));
	exit(n);
}
