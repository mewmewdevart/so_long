#include <stdio.h>

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

typedef struct s_map_objects_counts
{
	int	count_player;
	int	count_exit;
	int	count_collectible;
	int	count_wall;
	int	count_empty;
}	t_map_objects_counts;

typedef struct s_map_data
{
	int		size;
	int		rows;
	int		cols;
	char	**matrice;
}	t_map_data;

int ft_is_wall(t_map_data *data);

int main(void)
{
    // Initialization of structs
    t_map_data data = {
        .matrice = (char*[]){"1111111111111", "10010000000C1", "1000011111001", "1P0011E000001", "1111111111111", NULL}, // Lines of matrice : map_simple.ber
        .rows = 5,
        .cols = 13
    };
    t_map_objects_counts counts = {
        .count_player = 0,
        .count_exit = 0,
        .count_collectible = 0,
        .count_wall = 0,
        .count_empty = 0
    };

    if (ft_is_wall(&data))
        printf("Map is surrounded by walls\n");
    else
        printf("Map is not surrounded by walls\n");

    return (0);
}
// Check if the matrice is surrounded by walls
int ft_is_wall(t_map_data *data)
{
	int i;

	i = 0;
	while (i < data->cols)
	{
		if (data->matrice[0][i] != WALL || data->matrice[data->rows - 1][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < data->rows)
	{
		if (data->matrice[i][0] != WALL || data->matrice[i][data->cols - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}