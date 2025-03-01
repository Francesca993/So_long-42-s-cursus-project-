/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ft_to_allocate_map.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/03/01 13:44:03 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < rows)
	{
		if (map[i])
		{
			free(map[i]);
			map[i] = NULL;
		}
		i++;
	}
	free(map);
}

void	free_matrix(t_matrix *data)
{
	if (!data)
		return ;
	if (data->map)
	{
		free_map(data->map, data->rows);
		data->map = NULL;
	}
	if (data->map_cpy)
	{
		free_map(data->map_cpy, data->rows);
		data->map_cpy = NULL;
	}
	free(data->mlx);
	free(data);
}

t_matrix	*allocate_map(int rows)
{
	t_matrix	*data;

	data = (t_matrix *)ft_calloc(1, sizeof(t_matrix));
	if (!data)
	{
		perror("Errore nell'allocazione della struttura");
		return (NULL);
	}
	data->map = (char **)ft_calloc(rows, sizeof(char *));
	if (!data->map)
	{
		perror("Errore nell'allocazione della mappa");
		free(data);
		return (NULL);
	}
	data->rows = rows;
	return (data);
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
		return (-1);
	}
	line = get_next_line(fd);
	while (line != NULL )
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	if (count <= 0)
	{
		ft_printf("Errore: impossibile contare le righe della mappa.\n");
		return (1);
	}
	close(fd);
	return (count);
}
