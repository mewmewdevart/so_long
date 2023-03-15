#include <stdio.h>

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

typedef struct s_map_objects_counts
{
    int count_player;
    int count_exit;
    int count_collectible;
    int count_wall;
    int count_empty;
} t_map_objects_counts;

typedef struct s_map_data
{
    int     size;
    int     rows;
    int     cols;
    char    **matrice;
} t_map_data;

int ft_count_map_objects(t_map_data *data, t_map_objects_counts *counts);

int main(void)
{
    // Initialization of structs
    t_map_data data = {
        .matrice = (char*[]){"1111111111111", "10010000000C1", "1000011111001", "1P0011E000001", "1111111111111", NULL} // Lines of matrice : map_simple.ber
    };
    t_map_objects_counts counts = {
        .count_player = 0,
        .count_exit = 0,
        .count_collectible = 0,
        .count_wall = 0,
        .count_empty = 0
    };

    if (ft_count_map_objects(&data, &counts))
    {
        printf("Map is valid!\n");
        printf("Player count: %d\n", counts.count_player);
        printf("Exit count: %d\n", counts.count_exit);
        printf("Collectible count: %d\n", counts.count_collectible);
        printf("Wall count: %d\n", counts.count_wall);
        printf("Empty count: %d\n", counts.count_empty);
    }
    else
        printf("Map is invalid!\n");
    return (0);
}

int ft_count_map_objects(t_map_data *data, t_map_objects_counts *counts)
{
    char **map;
    int i;
    int j;

    i = 0;
    map = data->matrice;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == PLAYER)
                counts->count_player++;
            else if (map[i][j] == EXIT)
                counts->count_exit++;
            else if (map[i][j] == COLLECTIBLE)
                counts->count_collectible++;
            else if (map[i][j] == WALL)
                counts->count_wall++;
            else if (map[i][j] == EMPTY)
                counts->count_empty++;
            else if (map[i][j] != '\n')
                return(0); // Check if the map is invalid if there are invalid characters
            j++;
        }
        i++;
    }
    if (!(counts->count_player == 1 && counts->count_exit == 1 && counts->count_collectible >= 1))
        return(0);
    return(1);
}