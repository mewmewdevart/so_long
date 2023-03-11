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
# include "map.h"

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

typedef struct s_game
{
	void	*mlx;
	void	*window;
}	t_game;


/* -------◊	UTILS FUNCTIONS ◊------- */
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strchr_all_ocurrences(char *str, char ch);

/* -------◊	ERROR RESPONSES	◊------- */
void	ft_error_map(char *local, int n);
void	ft_error_game(char *local, int n);
void	ft_error_graphics(char *local, int n);

/* -------◊	INTERACTIONS MADE BY THE PLAYER WITH THE GAME ◊------- */
int		ft_check_keyboard(int key, t_game *game);
int ft_close_program(t_game *game);

#endif
