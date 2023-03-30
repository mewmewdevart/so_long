#include "../include/so_long.h"

void ft_player_up(t_game_instance *game_init)
{
    game_init->game_objs.player = mlx_xpm_file_to_image(game_init->mlx_ptr, "../rscs/sprites/Player_walkUp/walkAnimUp_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
    if (game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == EXIT && game_init->game_data.count_collectible == EMPTY)
    {
        mlx_clear_window(game_init->mlx_ptr, game_init->win_ptr);
        game_init->map_init.matrice[game_init->positions_init.player_row + 1][game_init->positions_init.player_col] = EMPTY;
        game_init->game_data.count_movements++;
        game_init->game_data.endgame++;
        ft_show_game(game_init);
    } else if (game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == WALL || game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == EXIT)
        game_init->positions_init.player_row++;
    else
    {
        mlx_clear_window(game_init->mlx_ptr, game_init->win_ptr);
        if (game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == COLLECTIBLE)
            game_init->game_data.count_collectible--;
        game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] = PLAYER;
        game_init->map_init.matrice[game_init->positions_init.player_row + 1][game_init->positions_init.player_col] = EMPTY;
        game_init->game_data.count_movements++;
         ft_show_game(game_init);
    }
}

void ft_player_left(t_game_instance *game_init)
{
    game_init->game_objs.player = mlx_xpm_file_to_image(game_init->mlx_ptr, "../rscs/sprites/Player_walkLeft/walkAnimLeft_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
    if (game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == EXIT && game_init->game_data.count_collectible == EMPTY)
    {
        mlx_clear_window(game_init->mlx_ptr, game_init->win_ptr);
        game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col + 1] = EMPTY;
        game_init->game_data.count_movements++;
        game_init->game_data.endgame++;
         ft_show_game(game_init);
    } else if (game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == WALL || game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == EXIT)
        game_init->positions_init.player_col++;
    else
    {
        mlx_clear_window(game_init->mlx_ptr, game_init->win_ptr);
        if (game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == COLLECTIBLE)
            game_init->game_data.count_collectible--;
        game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] = PLAYER;
        game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col +1 ] = EMPTY;
        game_init->game_data.count_movements++;
         ft_show_game(game_init);
    }
}

void ft_player_right(t_game_instance *game_init)
{
    game_init->game_objs.player = mlx_xpm_file_to_image(game_init->mlx_ptr, "../rscs/sprites/Player_walkRight/walkAnimRight_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
    if (game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == EXIT && game_init->game_data.count_collectible == EMPTY)
    {
        mlx_clear_window(game_init->mlx_ptr, game_init->win_ptr);
        game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col - 1] = EMPTY;
        game_init->game_data.count_movements++;
        game_init->game_data.endgame++;
         ft_show_game(game_init);
    } else if (game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == WALL || game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == EXIT)
        game_init->positions_init.player_col++;
    else
    {
        mlx_clear_window(game_init->mlx_ptr, game_init->win_ptr);
        if (game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == COLLECTIBLE)
            game_init->game_data.count_collectible--;
        game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] = PLAYER;
        game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col - 1] = EMPTY;
        game_init->game_data.count_movements++;
         ft_show_game(game_init);
    }
}

void ft_player_down(t_game_instance *game_init)
{
     game_init->game_objs.player = mlx_xpm_file_to_image(game_init->mlx_ptr, "../rscs/sprites/Player_walkDown/walkAnimDown_00.xpm", &game_init->game_objs.img_width, &game_init->game_objs.img_height);
    if (game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == EXIT && game_init->game_data.count_collectible == EMPTY)
    {
        mlx_clear_window(game_init->mlx_ptr, game_init->win_ptr);
        game_init->map_init.matrice[game_init->positions_init.player_row - 1][game_init->positions_init.player_col] = EMPTY;
        game_init->game_data.count_movements++;
        game_init->game_data.endgame++;
         ft_show_game(game_init);
    } else if (game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == WALL || game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == EXIT)
        game_init->positions_init.player_row++;
    else
    {
        mlx_clear_window(game_init->mlx_ptr, game_init->win_ptr);
        if (game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] == COLLECTIBLE)
            game_init->game_data.count_collectible--;
        game_init->map_init.matrice[game_init->positions_init.player_row][game_init->positions_init.player_col] = PLAYER;
        game_init->map_init.matrice[game_init->positions_init.player_row - 1][game_init->positions_init.player_col] = EMPTY;
        game_init->game_data.count_movements++;
         ft_show_game(game_init);
    }
}