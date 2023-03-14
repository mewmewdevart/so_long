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

void	ft_error_map(int n)
{
	if (n == 21)
		ft_printf("%sError\n This is a directory. Try to open one valid file! \n", COLOR_RED);
	else if (n == 22 || n == 52 || n == 59 || n == 24 || n == 5)
		ft_printf("%sError\n Usage: ./bin/so_long rscs/map/<filename>.ber \n", COLOR_RED);
	else if (n == 61)
		ft_printf("%sError\n No data available! Try create one valid map! \n", COLOR_RED);
	exit(n);
}
