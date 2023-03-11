/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:18:07 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/10 20:18:08 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_keyboard(int key, t_game *game)
{
	if (key == ESC)
	{
		ft_printf("Closing the windows and program.. \n");
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free (game->mlx);
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
	else if (key == RESTART)
	{
		ft_printf("Voce pressionou a tecla de restart!\n");
		ft_reset_game(game);
	}
	else
		ft_printf("\nYou pressed the key: %c -- %d \n", key, key);
		//ft_printf("You are pressing the wrong key.");
	return (0);
}

int ft_close_program(t_game *game)
{
	ft_printf("Closing the windows and program.. \n");
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free (game->mlx);
	exit (0);
}

void ft_reset_game(t_game *game)
{
    // Reiniciar os elementos do jogo para as configurações iniciais
	
    
    // Destruir e criar novamente a janela do jogo
    mlx_destroy_window(game->mlx, game->window);
    game->window = mlx_new_window(game->mlx, game->settings.width, game->settings.height, "so_long");

    // Atualizar a janela do jogo
   // mlx_put_image_to_window(game->mlx, game->window, game->image.img, 0, 0);
    
    // Reiniciar o jogo chamando a função main()
    main(game->argc, game->argv);
}