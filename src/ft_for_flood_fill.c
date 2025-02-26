/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_flood_fill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/26 12:59:46 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//riempe la mappa ovunque possa passare
void flood_fill(t_matrix *map, int row, int col)
{
	if ((map->map_cpy[row][col] != '\0'))
	{
		if((map->map_cpy[row][col] == '0') || ( map->map_cpy[row][col] == 'P') || (map->map_cpy[row][col] == 'C') || (map->map_cpy[row][col] == 'E'))
		{
			map->map_cpy[row][col] = 'X';
			flood_fill(map, row - 1, col);
			flood_fill(map, row + 1, col);
			flood_fill(map, row, col - 1);
			flood_fill(map, row, col + 1);
		}
	}
	else 
		return ;
}

//controlla dopo il riempimento con le X che non ci siano piu collezionabili e uscite
//ovvero che sono stati raccolti tutti o è stata raggiunta l'uscita
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
			if((map->map_cpy[y][x] == 'C') || (map->map_cpy[y][x] == 'E'))
			{
				ft_printf("Mappa non valida per percorso. \n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (ft_printf("Corretto mappa iterabile, collezionabili presi, uscita raggiunta\n"), 1);
}

//cerca la posizione iniziale da passare a flood fill
void		find_position_p(t_matrix *map)
{
	int		y;
	int		x;
	
	y= 0;

	while(y < map->rows)
	{
		x = 0;
		{
			while (x < map->cols)
			{
				if(map->map[y][x] == 'P')
				{
					map->position_p_row = y;
					map->position_p_col = x;
				}
				if (map->map[y][x] == 'C')
					map->coletionables++;
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
	y = 0;
	e = 0;
	while(y < map->rows)
	{
		x = 0;
			while (x < map->cols)
			{
				if(map->map[y][x] == 'P')
				{
					p++;
				}
				if(map->map[y][x] == 'E')
					e++;
			x++;
			}
		y++;
	}
	if (!((p == 1) && (e == 1)))
		return(ft_printf("Errore: trovate uscite o inizi multipli"), 0);
	return(1);
}