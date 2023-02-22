#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
    void *ptr_mlx;
    void *ptr_win;
    t_ptr ptr;
       
    ptr_mlx = mlx_init();
    ptr_win = mlx_new_window(ptr_mlx, 500, 500, "so_long");

    ptr.mlx = ptr_mlx;
    ptr.window = ptr_win;

    if (argc != 2)
        ft_error("argument", 22);
    if (argv[1])
        ft_map_open(argv[1]);


    mlx_key_hook(ptr.window, ft_check_keys, &ptr);
    mlx_loop(ptr_mlx);
    
	return (0);
}
