/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/18 15:46:16 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int rows)
{
	int	i;
	i = 0;

	if (!map)
		return;
	while (i < rows)
	{
		if(map[i])
			free(map[i]);
		i++;
	}
	free(map); // Libera l'array di puntatori
}

void	free_matrix(t_matrix *map_struct)
{
	if (!map_struct)
		return;

	if (map_struct->grid)
		free_map(map_struct->grid, map_struct->rows);

	free(map_struct); // Libera la struttura stessa
}
t_matrix *allocate_map(int rows)
{
	t_matrix *map_struct;

	map_struct = (t_matrix *)malloc(sizeof(t_matrix));
	if (!map_struct)
	{
		perror("Errore nell'allocazione della struttura");
		return (NULL);
	}
    map_struct->grid = (char **)malloc(rows * sizeof(char *));
	if (!map_struct->grid)
	{
		perror("Errore nell'allocazione della mappa");
		free(map_struct);
		return (NULL);
	}
	map_struct->rows = rows;

	return (map_struct);

}

t_matrix	*fill_map(t_matrix *map, char *filedescriptor)
{
	char	*line;
	int		y;
	int		fd;

	y = 0;
	fd = open(filedescriptor, O_RDONLY);
	if (fd == -1)
	{
		perror("Errore nell'apertura del file");
		close(fd);
		return (NULL);
	}
	while ((line = get_next_line(fd)) != NULL )
	{
		map->grid[y] = line;
		if (!map->grid[y])
		{
			free_map(map->grid, y);
			free(map);
			close(fd);
			return (NULL);
		}
        remove_new_line(map->grid[y]);
		y++;
	}
	map->rows = y;
	close(fd);
	return (map);
}

int	ft_count_rows(char *filename)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Errore nell'apertura del file");
		return (-1); // Segnala errore
	}
	while ((line = get_next_line(fd)) != NULL )
	{
		count++;
		free(line);
	}
	if (count <= 0)
	{
		ft_printf("Errore: impossibile contare le righe della mappa.\n");
		return (1);
	}
	close(fd);
	return (count);
}