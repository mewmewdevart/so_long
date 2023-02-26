/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:18:48 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/23 13:18:49 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int count_player;
int count_exit;
int count_collectible;
int count_wall;
int count_empty;


int	main(int argc, char *argv[])
{
	void	*ptr_mlx;
	void	*ptr_win;
	t_ptr	ptr;

	ptr_mlx = mlx_init();
	ptr_win = mlx_new_window(ptr_mlx, 500, 500, "so_long");
	ptr.mlx = ptr_mlx;
	ptr.window = ptr_win;
	if (argc != 2)
		ft_error_map("argument", 22);
	if (argv[1])
		ft_map_open(argv[1]);
	mlx_key_hook(ptr.window, ft_check_keys, &ptr);
	mlx_loop(ptr_mlx);
	return (0);
}
