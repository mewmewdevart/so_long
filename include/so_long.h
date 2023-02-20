#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/includes/libft.h"

# include <fcntl.h>

void    ft_error(int n);
void ft_map_open(char *map);
void ft_map_extension(char *map);
int ft_map_composed(char *map);

int	ft_strcmp(const char *s1, const char *s2);

#endif
