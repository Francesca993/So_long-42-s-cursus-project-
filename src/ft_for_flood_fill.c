/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_flood_fill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/19 16:06:34 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//controlla per flood fill se la casella in cui si trova è consentita
int		check_values_flood(t_matrix *map, int row, int col)
{
	char	values[3];
	int		i;

    values[0] = '1';
    values[1] = 'B';
    values[2] = 'X';
	i = 0;
	while ((i < 3) && (map->map_cpy[row][col] != values[i]))
		i++;
	if (i < 3)
	{
		
		return (1);
	} else {
		return (0);
	} 
}

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
void	check_values_map_cpy(t_matrix *map)
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
				return ;
			}
			x++;
		}
		y++;
	}
	ft_printf("Corretto mappa iterabile, collezionabili presi, uscita raggiunta");
}

//cerca la posizione iniziale da passare a flood fill
void		find_position_p(t_matrix *map)
{
	int		y;
	int		x;
	
	y= 0;
	count_p_e(map);
	while(y < map->rows)
	{
		x = 0;
		{
			while (x < map->cols)
			{
				if(map->grid[y][x] == 'P')
				{
					map->position_p_row = y;
					map->position_p_col = x;
					ft_printf("valore di y per flood fill: %d\n", map->position_p_row);
					ft_printf("valore di x per flood fill: %d\n", map->position_p_col);
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
	y = 0;
	e = 0;
	while(y < map->rows)
	{
		x = 0;
			while (x < map->cols)
			{
				if(map->grid[y][x] == 'P')
				{
					p++;
				}
				if(map->grid[y][x] == 'E')
					e++;
			x++;
			}
		y++;
	}
	ft_printf("valore di E:%d\n", e);
	ft_printf("valore di P:%d\n", p);
	if (!((p == 1) && (e == 1)))
		return(ft_printf("Errore: trovate uscite o inizi multipli"), 0);
	return(1);
}