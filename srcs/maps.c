/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:11:13 by larcrist          #+#    #+#             */
/*   Updated: 2023/03/10 20:11:14 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Open the file and storage the content in one struct
int	ft_open_map(char *map)
{
	int			fd;
	t_map_data	*map_data;

	// Aloca memória para a estrutura t_map_data
	map_data = ft_calloc(1, sizeof(t_map_data));
	if (!map_data)
		return (0);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		free(map_data);
		return (-1);
	}
	if (!ft_map_extension(map))
	{
		close(fd);
		free(map_data);
		return (0);
	}
	if (!ft_read_map(fd, map_data))
	{
		close(fd);
		free_map(map_data);
		return (0);
	}
	close(fd);
	free(map_data->matrice[0]);
	free(map_data);
	return (1);
}

// Read the file and storage the content in one struct
int ft_read_map(int fd, t_map_data *map_data)
{
    char *buffer;

    map_data->matrice = ft_calloc(6, sizeof(char *)); // Criar uma função que leia o tamanho do mapa e reserve espaço para ser usado em ft_calloc
	int i;
	i = 0;
    while (1)
    {
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break;
		map_data->matrice[i] = buffer;
		i++;
    }
	if (map_data->matrice[0]== NULL)
		return (0);
	ft_map_dimensions(map_data);

	// ~~~~~~ CHECANDO OS COMPONENTES ~~~~~~
	i = 0;
    ft_printf("\n Estou printando o conteudo : [ft_read_map] \n");
	while(map_data->matrice[i] != NULL)
	{
		ft_printf("%s", map_data->matrice[i]);
		i++;
	}
	ft_printf("\nColuna : %d ", map_data->cols);
	ft_printf(": Linhas : %d\n", map_data->rows);
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	if (!ft_is_valid_map(map_data))
		return (0);
    return (1);
}
 
 // Adaptar a função para verificar se a linha anteior possui o mesmo tamanho da linha atual /
//	verificar se todas as linhas possuem o mesmo tamnho e se todas as colunas também
void ft_map_dimensions(t_map_data *map_data)
{
	int	cols;
	int	rows;

	cols = 0;
	while (map_data->matrice[0][cols] && map_data->matrice[0][cols] != '\n')
		cols++;
	map_data->cols = cols;
	rows = 1;
	while (map_data->matrice[0][cols])
	{
		if (map_data->matrice[0][cols] == '\n')
			rows++;
		cols++;
	}
	map_data->rows = rows;
	ft_printf("\nColuna : %d\n", map_data->cols);
	ft_printf("\nLinhas : %d\n", map_data->rows);
}

/*
	// ~~~~~~ CHECANDO OS COMPONENTES ~~~~~~
	i = 0;
    ft_printf("\n Estou printando o conteudo : [ ] \n");
	while(map_data->matrice[i] != NULL)
	{
		ft_printf("%s", map_data->matrice[i]);
		i++;
	}
	ft_printf("\nColuna : %d ", map_data->cols);
	ft_printf(": Linhas : %d\n", map_data->rows);
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/