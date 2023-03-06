#include "../include/so_long.h"

//Clear all structures of map before checking
t_map_content	ft_map_start(void)
{
	t_map_content	map_data;

	map_data.count_player = 0;
	map_data.count_exit = 0;
	map_data.count_collectible = 0;
	map_data.count_wall = 0;
	map_data.count_empty = 0;
	return (map_data);
}

t_map_content ft_map_composed(char *map)
{
    t_map_content	map_content;
    int				i;

    if (!map)
    {
        map_content.count_player = -1;
        return (map_content);
    }
    i = -1;
    while (map[++i])
    {
        if (map[i] == PLAYER)
            map_content.count_player++;
        else if (map[i] == EXIT)
            map_content.count_exit++;
        else if (map[i] == COLLECTIBLE)
            map_content.count_collectible++;
        else if (map[i] == WALL)
            map_content.count_wall++;
        else if (map[i] == EMPTY)
            map_content.count_empty++;
    }
    return (map_content);
}

int ft_map_composed_valid(t_map_content *map_layers)
{
	if (map_layers->count_player != 1 || map_layers->count_exit != 1 || map_layers->count_collectible < 1)
	{
		ft_error_map("Invalid map!", 61);
		return(-1);
	}
	return(1);
}