/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_validate_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/03/01 17:30:20 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// copio la mappa
//cerca la posizione iniziale da passare a flood fill e controlla 
//che non ci siano piu di un'unscita o di una posizione di partenza
//riempe la mappa ovunque possa passare
//controlla dopo il riempimento con le X che non ci 
//siano piu collezionabili e uscite
//ovvero che sono stati raccolti tutti o è stata raggiunta l'uscita
int	check_if_valid_path(t_matrix *data)
{
	count_cols(data);
	map_copy(data);
	data->coll_fill_found = 0;
	if (!data->map_cpy)
	{
		ft_printf("Errore: allocazione della copia della mappa fallita.\n");
		return (0);
	}
	if (!(count_c(data)))
		return (0);
	if (!(count_p_e(data)))
		return (0);
	ft_printf("Mappa copiata caricata:\n");
	find_position_p(data);
	flood_fill(data, data->position_p_row, data->position_p_col);
	ft_printf("Mappa copiata dopo flood fill:\n");
	return (1);
}

int	map_checks(t_matrix *data)
{
	if (!(check_map_rect(data, data->rows)))
		return (0);
	if (!(check_map_walls(data, data->rows)))
		return (0);
	if (!(check_if_valid_path(data)))
		return (0);
	if ((data->coll_fill_found) == (data->colletionables))
		return (1);
	else
	{
		ft_printf("Errore: Non tutti i collezionabili sono stati trovati!\n");
		return (0);
	}
	return (1);
}
