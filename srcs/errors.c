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
		ft_printf("%sThis is a directory. Try to open one valid file! \n", COLOR_RED);
		exit(n);
	}
	else if (n == 22 || n == 52 || n == 59 || n == 24 || n == 5)
	{
		ft_printf("%s: %s\n", local, strerror(n));
		ft_printf("%sUsage: ./so.long <filename>.ber\n", COLOR_RED);
		exit(n);
	}
	else if (n == 61)
	{
		ft_printf("%s: %s\n", local, strerror(n));
		ft_printf("%sNo data available! Try create one valid map!\n", COLOR_RED);
		exit(n);
	}
	else
		ft_printf("%s %s: %s\n", COLOR_RED, local, strerror(n));
	exit(n);
}
