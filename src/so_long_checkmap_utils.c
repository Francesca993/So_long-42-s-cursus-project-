/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checkmap_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/18 15:45:30 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	remove_new_line(char *str)
{
	int	count;

	if (!str)
		return (0);
	count = ft_strlen(str);
	if ((count > 0) && (str[count - 1] == '\n'))
	{
		str[count - 1] = '\0';
	}
	return (1);
}

int	check_map_rect(t_matrix *map_struct, int rows)
{
	int	y;
	int	len;

	y = 0;
	if (rows <= 0)
		return (0);
	len = (int)ft_strlen(map_struct->grid[0]);
	while (y < rows)
	{
		if (((int)ft_strlen(map_struct->grid[y])) != len)
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
	check_map_walls(map_struct, rows);
	return (1);
}

int	check_map_walls_x(t_matrix *map_struct, int rows)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map_struct->grid[y][x] != '\0')
	{
		if (map_struct->grid[y][x] != '1')
		{
			ft_printf("Errore: le righe della mappa non sono tutte chiuse!\n");
			return (0);
		}
		x++;
	}
	while (y < rows -1)
	{
		if (map_struct->grid[y][x - 1] != '1')
		{
			ft_printf("Errore: le righe della mappa non sono tutte chiuse!\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_map_walls(t_matrix *map_struct, int rows)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (check_map_walls_x(map_struct, rows))
	{
		while (y < rows - 1)
		{
			if (map_struct->grid[y][x] != '1')
				return (ft_printf("Errore: le righe della mappa non sono tutte chiuse!\n"), 0);
			y++;
		}
		while (map_struct->grid[y][x] != '\0')
		{
			if (map_struct->grid[y][x] != '1')
			{
				ft_printf("Errore: le righe della mappa non sono tutte chiuse!\n");
				return (0);
			}
			x++;
		}
	}
	ft_printf("Corretto: le righe della mappa sono tutte chiuse!\n");
	return (1);
}
