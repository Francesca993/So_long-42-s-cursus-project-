/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_flood_fill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/03/01 17:29:58 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_c_remaining(t_matrix *map)
{
	int		y;
	int		c;
	int		x;

	c = 0;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->map_cpy[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

//riempe la mappa ovunque possa passare
//controlla dopo il riempimento con le X che 
//non ci siano piu collezionabili e uscite
//ovvero che sono stati raccolti tutti o è stata raggiunta l'uscita
void	flood_fill(t_matrix *map, int row, int col)
{
	if ((map->map_cpy[row][col] != '\0'))
	{
		if ((map->map_cpy[row][col] == '1') || (map->map_cpy[row][col] == 'X'))
			return ;
		if (map->map_cpy[row][col] == 'C')
		{
			(map->coll_fill_found)++;
			ft_printf("%d\n", map->coll_fill_found);
		}
		else if (map->map_cpy[row][col] == 'E')
		{
			map->map_cpy[row][col] = 'X';
			return ;
		}
		map->map_cpy[row][col] = 'X';
		flood_fill(map, row - 1, col);
		flood_fill(map, row + 1, col);
		flood_fill(map, row, col - 1);
		flood_fill(map, row, col + 1);
	}
	else
		return ;
}

int	check_values_map_cpy(t_matrix *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if ((map->map_cpy[y][x] == 'C') || (map->map_cpy[y][x] == 'E'))
			{
				ft_printf("Mappa non valida per percorso. \n");
				return (0);
			}
			x++;
		}
		y++;
	}
	ft_printf("Corretto mappa iterabile\n");
	ft_printf("ollezionabili presi, uscita raggiunta\n");
	return (1);
}

//cerca la posizione iniziale da passare a flood fill e conta i collezionabili
void	find_position_p(t_matrix *map)
{
	int		y;
	int		x;

	y = 0;
	map->colletionables = 0;
	while (y < map->rows)
	{
		x = 0;
		{
			while (x < map->cols)
			{
				if (map->map[y][x] == 'P')
				{
					map->position_p_row = y;
					map->position_p_col = x;
				}
				if (map->map[y][x] == 'C')
					map->colletionables++;
				x++;
			}
		}
		y++;
	}
}
