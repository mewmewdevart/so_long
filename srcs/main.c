/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:18:24 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/10 20:18:25 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map_data				map_data;
	t_map_objects_counts	data;

	ft_initialize_map_data(&map_data, &data);
	ft_initialize_game(argc, argv);
	free_map(&map_data);
	return (0);
}
