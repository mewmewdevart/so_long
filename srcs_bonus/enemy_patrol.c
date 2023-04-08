#include "../include/so_long_bonus.h"

void ft_enemy_events(t_game_instance *game_init) 
{
	int enemy_row;
	int enemy_col;
	int enemy_direction;

	ft_locate_enemy(game_init);
	enemy_row = game_init->positions_init.enemy_row;
	enemy_col = game_init->positions_init.enemy_col;
	enemy_direction = game_init->positions_init.enemy_direction;
	if (enemy_direction == 1) 
	{ // move para a direita
		if (game_init->map_init.matrice[enemy_row][enemy_col + 1] == PLAYER)
		{
			enemy_col++;// O inimigo encontrou o jogador então continua
			ft_printf("\nGame over! ");
			ft_printf("Better luck next time! Your score was [%d] moves!\n",  game_init->game_data.count_movements);
			ft_exit_program(game_init);
		}
		else if (enemy_col == game_init->map_init.cols_matrice - 2 || game_init->map_init.matrice[enemy_row][enemy_col + 1] != EMPTY) 
		{
			enemy_direction = -1;
			enemy_col--;
		} 
		else
			enemy_col++;
	} 
	else 
	{ // move para a esquerda
		if (game_init->map_init.matrice[enemy_row][enemy_col - 1] == PLAYER)
		{
			enemy_col--;
			ft_printf("\nGame over! ");
			ft_printf("Better luck next time! Your score was [%d] moves!\n",  game_init->game_data.count_movements);
			ft_exit_program(game_init);
		}
		else if (enemy_col == 1 || game_init->map_init.matrice[enemy_row][enemy_col - 1] != EMPTY) 
		{
			enemy_direction = 1;
			enemy_col++;
		} 
		else
			enemy_col--;
	}
	game_init->map_init.matrice[enemy_row][game_init->positions_init.enemy_col] = EMPTY;
	game_init->map_init.matrice[enemy_row][enemy_col] = ENEMY;
	game_init->positions_init.enemy_col = enemy_col;
	game_init->positions_init.enemy_direction = enemy_direction;
}

void ft_locate_enemy(t_game_instance *game_init)
{
    int col;
    int row;

    row = 0;
    while (game_init->map_init.matrice[row] != NULL)
    {
        col = 0;
        while (game_init->map_init.matrice[row][col] != '\0') 
        {
            if (game_init->map_init.matrice[row][col] == ENEMY) 
            {
                game_init->positions_init.enemy_row = row;
                game_init->positions_init.enemy_col = col;
                return;
            }
            col++;
        }
        row++;
    }
}
