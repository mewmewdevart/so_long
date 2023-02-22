#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/includes/libft.h"

# include <fcntl.h> //read
# include <string.h> //strerror

# define ESC 65307 //keywords
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363

typedef struct s_ptr
{
    void *mlx;
    void *window;
}   t_ptr;

void	ft_error(char *local, int n);
int ft_map_open(char *map);
int ft_map_extension(char *map);
int ft_map_composed(char *map);

int ft_check_keys(int key, t_ptr *ptr);

int	ft_strcmp(const char *s1, const char *s2);

#endif
