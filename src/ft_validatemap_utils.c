/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validatemap_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/19 13:03:00 by fmontini         ###   ########.fr       */
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

	ft_printf("ciao 1!\n");

	if (!(check_map_walls_x(data, rows)))
		return (0);
	while (y < rows - 1)
		{
			if (data->map[y][x] != '1')
			{
				ft_printf("Errore: le righe della mappa non sono tutte chiuse!\n");
				return (0);
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
