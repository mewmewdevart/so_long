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

void	ft_error(int n)
{
	if (n == 22 || n == 52)
	{
		ft_printf("[EINVAL] or [EBADE] Error: Invalid argument/Invalid exchange. \n");
		ft_printf("Recommendation: ./so.long <filename>.ber\n");
		exit(n);
	}
	else if (n == 24)
	{
		ft_printf("[EMFILE] Error: \n");
		ft_printf("Too many open files!\n");
		exit(n);
	}
	exit(n);
}

//function to open the map
void ft_map_open(char *map)
{
	ft_map_extension(map);
}

//function to check the extension is .ber
void	ft_map_extension(char *map)
{
	char	*extension;
	char	*file_extension;

	extension = ".ber";
	file_extension = ft_strrchr(map, '.');
	if (map[ft_strlen(map) - 1] == '/')
		ft_error(24);
	else if (file_extension && ft_strcmp(file_extension, extension) == 0)
		ft_printf("It is a good extension!\n");
	else
		ft_error(22);
}

//function to read if the function have walls etc...
int ft_map_composed(char *map)
{
	ft_printf("%s", map);
	return(0);
}