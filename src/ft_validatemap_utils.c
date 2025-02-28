/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validatemap_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/28 15:05:13 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_rect(t_matrix *data, int rows)
{
	int	y;
	int	len;

	y = 0;
	if (rows <= 0)
		return (0);
	len = (int)ft_strlen(data->map[0]);
	while (y < rows)
	{
		if (((int)ft_strlen(data->map[y])) != len)
		{
			ft_printf("Errore: le righe della mappa non sono tutte uguali!\n");
			return (0);
		}
		y++;
	}
	if (len == rows)
	{
		ft_printf("Errore: la mappa non è rettangolare.\n");
		return (0);
	}
	ft_printf("Le righe della mappa sono tutte uguali ed è rettangolare.\n");
	return (1);
}

int	check_map_walls_x(t_matrix *data, int rows)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y][x] != '\0')
	{
		if (data->map[y][x] != '1')
		{
			ft_printf("Errore: le righe della mappa non sono tutte chiuse!\n");
			return (0);
		}
		x++;
	}
	while (y < rows -1)
	{
		if (data->map[y][x - 1] != '1')
		{
			ft_printf("Errore: le righe della mappa non sono tutte chiuse!\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_map_walls(t_matrix *data, int rows)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!(check_map_walls_x(data, rows)))
		return (0);
	while (y < rows - 1)
		{
			if (data->map[y][x] != '1')
			{
				return (ft_printf("Errore: le righe della mappa non sono tutte chiuse!\n"), 0);
			}
			y++;
		}
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] != '1')
			{
				return (ft_printf("Errore: le righe della mappa non sono tutte chiuse!\n"), 0);
			}
			x++;
		}
		ft_printf("Corretto: le righe della mappa sono tutte chiuse!\n");
	return (1);
}
int		count_c(t_matrix *map)
{
	int		y;
	int		c;
	int		x;
	
	c = 0;
	y = 0;
	while(y < map->rows)
	{
		x = 0;
			while (x < map->cols)
			{
				if(map->map[y][x] == 'C')
					c++;
			x++;
			}
		y++;
	}
	if (c == 0)
	{
		ft_printf("Non ci sono collezionabili nella mappa!");
		return (0);	
	}
	return(1);	
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
					p++;
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
