/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:51:17 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/13 11:51:18 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

// Auxiliary Function : ft_read_map
int	ft_check_read(t_game_instance *game_init)
{
	if (game_init->map_init.matrice[0] == NULL
		|| !ft_update_map_dimensions(game_init) || !ft_is_valid_map(game_init))
	{
		ft_free_map(game_init);
		return (0);
	}
	return (1);
}

// Auxiliary Function  : ft_update_map_dimensions
int	ft_map_dimensions(t_game_instance *game_init)
{
	char	*row;
	int		row_len;
	int		row_index;

	row_index = 0;
	row = game_init->map_init.matrice[0];
	while (row[game_init->map_init.rows_matrice]
		&& row[game_init->map_init.cols_matrice] != '\n')
		game_init->map_init.cols_matrice++;
	while (1)
	{
		row = game_init->map_init.matrice[row_index];
		if (!row)
			break ;
		row_len = ft_strlen(row) - (row[ft_strlen(row) - 1] == '\n');
		if (row_len != game_init->map_init.cols_matrice)
		{
			game_init->map_init.rows_matrice = 0;
			return (0);
		}
		game_init->map_init.rows_matrice++;
		row_index++;
	}
	return (1);
}

// Auxiliary Function  : ft_read_count_map
int	count_newlines(int fd, char *buffer)
{
	int		count;
	ssize_t	n_read;
	int		i;

	count = 0;
	while (1)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read < 0)
			return (0);
		if (n_read == 0)
			break ;
		i = 0;
		while (i < n_read)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
	}
	return (count);
}
