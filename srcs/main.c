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

int	main(int argc, char *argv[])
{
	void	*ptr_mlx;
	void	*ptr_win;
	t_game	ptr;

	ptr_mlx = mlx_init();
	ptr_win = mlx_new_window(ptr_mlx, 500, 500, "so_long");
	if (argc != 2)
		ft_error_map("argument", 22);
	if (argv[1])
	{
		if (ft_open_map(argv[1]) == -1)
			ft_error_map("failed to open or read map file", 23);
	}
	ptr.mlx = ptr_mlx;
	ptr.window = ptr_win;
	mlx_hook(ptr.window, 17, 0, ft_close_program, &ptr);
	mlx_key_hook(ptr.window, ft_check_keyboard, &ptr);
	mlx_loop(ptr_mlx);
	return (0);
}
