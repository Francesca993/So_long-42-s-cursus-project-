/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_floodfill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/18 15:45:30 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_copy(t_matrix *map)
{
	int		i;

	map->map_cpy = (char **) malloc(sizeof(char *) * (game->rows + 1));
	if (map->map_cpy == NULL)
		ft_printf("Errore nell'allocazione della memoria nella copia della mappa")
	x = 0;
	while (x < map->rows)
	{
		map->map_cpy[i] = ft_strdup(map->grid[i]);
		i++;
	}
	map->map_cpy[i] = NULL;
}

int		check_values(t_data *map, int row, int col)
{
	const char	values[];
	int		i;

	values = '1', 'B', 'X';
	i = 0;
	while ((i < 3) && (map->map_cpy[row][col] != values[i]))
		i++;
	if (i < 3)
	{
		map->map_cpy[row][col] = 'X';
		return (1);
	} else {
		return (0)
	} 
}

void flood_fill(t_matrix *map, int row, int col)
{
	if(check_values(map, row, col) = 1)
	{
		flood_fill(map, row - 1, col);
		flood_fill(map, row + 1, col);
		flood_fill(map, row, col - 1);
		flood_fill(map, row, col + 1);
	}
	else 
		return ;
}

void	check_values_map_cpy(t_matrix *map)
{
	int		y;
	int		x;

	i = 0;
	while (i < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if((map->map_cpy[y][x] == 'C') || (map->map_cpy[y][x] == 'E'))
			{
				ft_printf("Mappa non valida per percorso. \n");
				return ;
			}
			x++;
		}
		y++;
	}
}

