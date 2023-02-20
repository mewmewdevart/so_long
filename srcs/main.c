#include "../include/so_long.h"


int main (int argc, char *argv[])
{
	if (argc != 2)
		ft_error(22);
	if (argv[1])
		ft_map_open(argv[1]);
    return (0);
}
