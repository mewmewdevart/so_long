/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:21:47 by larcrist          #+#    #+#             */
/*   Updated: 2023/02/28 14:35:52 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/includes/libft.h"

# include <fcntl.h> // Read
# include <string.h> // Strerror

# define ESC 65307 // Keywords
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363

# define PLAYER 'P' // Map compositions
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

typedef struct s_ptr
{
	void	*mlx;
	void	*window;
}	t_ptr;

typedef struct	s_map_content
{
	int	count_player;
	int	count_exit;
	int	count_collectible;
	int	count_wall;
	int	count_empty;
}	t_map_content;

/* -------◊	UTILS FUNCTIONS ◊------- */
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strchr_all_oc(char *str, char ch);

/* -------◊	MAP ACTIONS	◊------- */
int		ft_map_open(char *map);
int		ft_map_extension(char *map);
int		ft_isrectangular(char *map);
//int     ft_map_behaviors(char *map);
int		ft_count_rows(char *map, int size_content);
int		ft_count_cols(char *map, int size_content);
int     ft_check_walls(char *map);
int     ft_count_aligned(char *map, int size_content);
t_map_content   ft_map_start(void);
t_map_content	ft_map_composed(char *map);
int ft_map_composed_valid(t_map_content *map_info);
//int		ft_map_composed(char *map);

/* -------◊	ERROR RESPONSES	◊------- */
void	ft_error_map(char *local, int n);
void	ft_error_game(char *local, int n);
void	ft_error_graphics(char *local, int n);

int		ft_check_keys(int key, t_ptr *ptr);

#endif
