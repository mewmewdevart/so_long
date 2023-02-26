/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:21:47 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/25 20:07:55 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define PLAYER 'P' //map compositions
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

typedef struct s_ptr
{
	void	*mlx;
	void	*window;
}	t_ptr;

int		ft_strcmp(const char *s1, const char *s2);
int ft_strchr_all_oc(char *str, char ch);

int		ft_map_open(char *map);
int		ft_map_extension(char *map);
int		ft_map_composed(char *map);

void	ft_error_map(char *local, int n);
void	ft_error_game(char *local, int n);
void	ft_error_graphics(char *local, int n);

int		ft_check_keys(int key, t_ptr *ptr);

#endif
