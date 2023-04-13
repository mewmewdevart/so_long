/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:13:15 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/10 17:19:22 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// Protótipos das funções auxiliares
static void	ft_draw_top(t_game_instance *game_init, int row, int col, int cols);
static void	ft_draw_bot(t_game_instance *game_init, int row, int col, int cols);
static void	ft_draw_mid(t_game_instance *game_init, int row, int col, int cols);

// Função principal para desenhar as paredes
void	ft_draw_wall(t_game_instance *game_init)
{
	int	row;
	int	col;
	int	rows;
	int	cols;

	rows = game_init->map_init.rows_matrice;
	cols = game_init->map_init.cols_matrice;
	row = 0;
	while (row < rows)
	{
		col = 0;
		while (col < cols)
		{
			if (row == 0)
				ft_draw_top(game_init, row, col, cols);
			else if (row == rows - 1)
				ft_draw_bot(game_init, row, col, cols);
			else
				ft_draw_mid(game_init, row, col, cols);
			col++;
		}
		row++;
	}
}

// Função auxiliar para desenhar a parte de cima da parede
static void	ft_draw_top(t_game_instance *game_init, int row, int col, int cols)
{
	if (col == 0)
		ft_set(game_init, game_init->game_objs.wall_up0, col, row);
	else if (col == cols - 1)
		ft_set(game_init, game_init->game_objs.wall_up2, col, row);
	else
		ft_set(game_init, game_init->game_objs.wall_up1, col, row);
}

// Função auxiliar para desenhar a parte de baixo da parede
static void	ft_draw_bot(t_game_instance *game_init, int row, int col, int cols)
{
	if (col == 0)
		ft_set(game_init, game_init->game_objs.wall_down0, col, row);
	else if (col == cols - 1)
		ft_set(game_init, game_init->game_objs.wall_down2, col, row);
	else
		ft_set(game_init, game_init->game_objs.wall_down1, col, row);
}

// Função auxiliar para desenhar a parte do meio da parede
static void	ft_draw_mid(t_game_instance *game_init, int row, int col, int cols)
{
	if (col == 0)
		ft_set(game_init, game_init->game_objs.wall_middle0, col, row);
	else if (col == cols - 1)
		ft_set(game_init, game_init->game_objs.wall_middle2, col, row);
	else if (game_init->map_init.matrice[row][col] == WALL)
		ft_set(game_init, game_init->game_objs.wall_middle1, col, row);
}
