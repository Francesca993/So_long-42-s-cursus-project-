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

//copia la mappa in quella da utilizzare per flood fill
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

//controlla per flood fill se la casella in cui si trova è consentita
int		check_values_flood(t_data *map, int row, int col)
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

//riempe la mappa ovunque possa passare
void flood_fill(t_matrix *map, int row, int col)
{
	if(check_values_flood(map, row, col) = 1)
	{
		flood_fill(map, row - 1, col);
		flood_fill(map, row + 1, col);
		flood_fill(map, row, col - 1);
		flood_fill(map, row, col + 1);
	}
	else 
		return ;
}

//controlla dopo il riempimento con le X che non ci siano piu collezionabili e uscite
//ovvero che sono stati raccolti tutti o è stata raggiunta l'uscita
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

//cerca la posizione iniziale da passare a flood fill
void		find_position_p(t_matrix *map)
{
	int		y;
	int		x;
	
	y= 0;
	if(!(ft count_p_e(map)))
		return ;
	while(y < map->rows)
	{
		x = 0;
		{
			while (x < map->cols)
			{
				if(map[y][x] == 'P')
				{
					map->position_p_row = y;
					map->position_p_col = x;
				}
			x++;
			}
		}
		y++;
	}
}

// controlla che non ci siano piu di un'unscita o di una posizione di partenza
int		count_p_e(t_matrix	*map)
{
	int		y;
	int		p;
	int		e;
	int		x;
	
	p = 0;
	y= 0;
	e = 0;
	while(y < map->rows)
	{
		x = 0;
		{
			while (x < map->cols)
			{
				if(map[y][x] == 'P')
					p++;
				if(map[y][x] == 'E')
					e++;
			x++;
			}
		}
		y++;
	}
	if ((p != 1) && (e != 1))
		return(ft_printf("Errore: trovate uscite o inizi multipli"), 0);
	return(1);
}

// tutto insieme?
int		check_if_valid_path()
{
	//copia la mappa
	map_copy(t_matrix *map);
	//cerca la posizione iniziale da passare a flood fill e controlla 
	//che non ci siano piu di un'unscita o di una posizione di partenza
	find_position_p(t_matrix *map);
	//riempe la mappa ovunque possa passare
	flood_fill(t_matrix *map, int row, int col);
	//controlla dopo il riempimento con le X che non ci siano piu collezionabili e uscite
	//ovvero che sono stati raccolti tutti o è stata raggiunta l'uscita
	check_values_map_cpy(t_matrix *map);

	

}