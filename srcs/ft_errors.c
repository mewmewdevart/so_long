/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:36:17 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/20 16:36:19 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	ft_error(char *local, int n)
{
	if (n == 5)
	{
		ft_printf("%s: %s\n", local, strerror(n));
		ft_printf("Input/output error\n");
		exit(n);
	}
	else if (n == 21)
	{
		ft_printf("%s: %s\n", local, strerror(n));
		ft_printf("This is a directory. Try to open one file! \n");
		exit(n);
	}
	else if (n == 22 || n == 52)
	{
		ft_printf("%s: %s\n", local, strerror(n));
		ft_printf("Usage: ./so.long <filename>.ber\n");
		exit(n);
	}
	else if (n == 24)
	{
		ft_printf("%s: %s\n", local, strerror(n));
		ft_printf("Too many open files!\n");
		exit(n);
	}
	else if (n == 59)
	{
		ft_printf("%s: %s\n", local, strerror(n));
		ft_printf("Bad font file format!\n");
		exit(n);
	}
	ft_printf("%s: %s\n", local, strerror(n));
	exit(n);
}