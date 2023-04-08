#include "../include/so_long_bonus.h"

void ft_draw_wall(t_game_instance *game_init)
{
    int i;
    int j;
    int rows;
    int cols;

    i = 0;
    rows = game_init->map_init.rows_matrice;
    cols = game_init->map_init.cols_matrice;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            if (i == 0) // primeira linha
            {
                if (j == 0) // primeira coluna
                    ft_set(game_init, game_init->game_objs.wall_up0, j, i);
                else if (j == cols - 1) // ultima coluna
                    ft_set(game_init, game_init->game_objs.wall_up2, j, i);
                else // resto da primeira linha
                    ft_set(game_init, game_init->game_objs.wall_up1, j, i);
            }
            else if (i == rows - 1) // ultima linha
            {
                if (j == 0) // primeira coluna
                    ft_set(game_init, game_init->game_objs.wall_down0, j, i);
                else if (j == cols - 1) // ultima coluna
                    ft_set(game_init, game_init->game_objs.wall_down2, j, i);
                else // resto da ultima linha
                    ft_set(game_init, game_init->game_objs.wall_down1, j, i);
            }
            else // resto da matriz
            {
                if (j == 0) // primeira coluna
                    ft_set(game_init, game_init->game_objs.wall_middle0, j, i);
                else if (j == cols - 1) // ultima coluna
                    ft_set(game_init, game_init->game_objs.wall_middle2, j, i);
                else if (game_init->map_init.matrice[i][j] == WALL) // encontrou uma parede
                ft_set(game_init, game_init->game_objs.wall_middle1, j, i);
            }
            j++;
        }
        i++;
    }
}

