#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/includes/libft.h"

# include <fcntl.h> //read
# include <string.h> //strerror

void	ft_error(char *local, int n);
int ft_map_open(char *map);
int ft_map_extension(char *map);
int ft_map_composed(char *map);

int	ft_strcmp(const char *s1, const char *s2);

#endif
