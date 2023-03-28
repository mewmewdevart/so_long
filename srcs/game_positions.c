#include "../include/so_long.h"

void ft_positions_player(t_game_instance *game_init)
{
    int x_row = 0;
    int y_col = 0;

    while (game_init->map_init.matrice[x_row] != NULL)
    {
        y_col = 0;
        while (game_init->map_init.matrice[x_row][y_col] != '\0')
        {
            if (game_init->map_init.matrice[x_row][y_col] == PLAYER)
            {
                game_init->map_init.positions.player_row = x_row;
                game_init->map_init.positions.player_col = y_col;
                return ;
            }
            y_col++;
        }
        x_row++;
    }
}

/*

void ft_update_player_position(t_game_instance *game_init)
{
    int update_row;
    int update_col;

    update_row = game_init->positions_init.player_row;
    update_col = game_init->positions_init.player_col;

    // Verifica a direcao em que o jogador deve se mover e atualiza as coordenadas
    if (game_init->game_objs.player_up && game_init->positions_init.player_row > 0)
        update_row = game_init->positions_init.player_row - 1;
    else if (game_init->game_objs.player_down && game_init->positions_init.player_row < game_init->map_init.rows_matrice - 1)
        update_row = game_init->positions_init.player_row + 1;
    else if (game_init->game_objs.player_left && game_init->positions_init.player_col > 0)
        update_col = game_init->positions_init.player_col - 1;
    else if (game_init->game_objs.player_right && game_init->positions_init.player_col < game_init->map_init.cols_matrice - 1)
        update_col = game_init->positions_init.player_col + 1;

    ///Atualizar as posições do jogador no mapa
    if (update_row != game_init->positions_init.player_row || update_col != game_init->positions_init.player_col)
    {
        if(game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == COLLECTIBLE)
            ft_printf("It is a collectible\n");
        game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] = EMPTY;
        game_init->positions_init.player_row = update_row;
        game_init->positions_init.player_col = update_col;
        game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] = PLAYER;


        //FAZER CONFIRMAÇÃO DE QUANDO UMA TECLA APERTADA FOR VALIDA E MOVIMENTADA, É CONTANDO NO DISPLAY
    }
    //ft_printf("O Player está na linha: %d\n", game_init->positions_init.player_row);
    //ft_printf("O Player está na coluna: %d\n", game_init->positions_init.player_col);
} */