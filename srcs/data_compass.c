#include "../include/so_long.h"

// Function to compass all positions inside the map
t_compass ft_compass_positions(t_map_data map_data)
{
    t_compass compass = {0};

    compass = ft_compass_player(&map_data, &compass);
    ft_compass_exit(&map_data, &compass);
    return (compass);
}

t_compass ft_compass_player(t_map_data *map_data, t_compass *compass)
{
    int i;
    int j;

    i = 0;
    while (map_data->matrice[i] != NULL)
    {
        j = 0;
        while(map_data->matrice[i][j] != '\0')
        {
            if (map_data->matrice[i][j] == PLAYER)
            {
                compass->player_row = i;
                compass->player_col = j;
                return (*compass);
            }
            j++;
        }
        i++;
    }
    return (*compass);
}

/*

t_compass ft_compass_player(t_keysword *keys, t_map_data *map_data, t_compass *compass) // Chamar a key word aqui
{
    int i;
    int j;

    i = 0;
    while (map_data->matrice[i] != NULL)
    {
        j = 0;
        while(map_data->matrice[i][j] != '\0')
        {
            if (map_data->matrice[i][j] == PLAYER) //NECESSARIO CHECAR SE TEM FREE SPACE OU WALL
            {
                compass->player_row = i;
                compass->player_col = j;
                if (keys->pressed == W || keys->pressed == UP)
                    compass->player_row -= 1;
                else if (keys->pressed == A || keys->pressed == LEFT)
                    compass->player_col -= 1;
                else if (keys->pressed == S || keys->pressed == DOWN)
                    compass->player_row += 1;
                else if (keys->pressed == D || keys->pressed == RIGHT)
                    compass->player_col += 1;
                ft_printf("O Player está na linha: %d\n", compass->player_row);
                ft_printf("O Player está na coluna: %d\n", compass->player_col);
                return (*compass);
            }
            j++;
        }
        i++;
    }
    return (*compass);
}
*/

t_compass ft_compass_exit(t_map_data *map_data, t_compass *compass)
{
    int i;
    int j;

    i = 0;
    while (map_data->matrice[i] != NULL)
    {
        j = 0;
        while(map_data->matrice[i][j] != '\0')
        {
            if (map_data->matrice[i][j] == EXIT)
            {
                compass->exit_row = i;
                compass->exit_col = j;
                ft_printf("A Saida está na linha: %d\n", compass->exit_row);
                ft_printf("A Saida está na coluna: %d\n", compass->exit_col);
                return (*compass);
            }
            j++;
        }
        i++;
    }
    return (*compass);
}
