
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

int		check_if_valid_path(t_matrix *data)
{
	count_cols(data);
    //copia la mappa
    map_copy(data);
	//cerca la posizione iniziale da passare a flood fill e controlla 
	//che non ci siano piu di un'unscita o di una posizione di partenza
    ft_printf("Mappa copiata caricata:\n");
	for (int i = 0; i < data->rows; i++)
		printf("%s\n", data->map_cpy[i]);
	find_position_p(data);
	ft_printf("valore passato a flood fill: %c\n", data->map_cpy[data->position_p_row][data->position_p_col]);
	//riempe la mappa ovunque possa passare
	flood_fill(data, data->position_p_row, data->position_p_col);
    ft_printf("Mappa copiata dopo flood fill:\n");
	for (int i = 0; i < data->rows; i++)
	printf("%s\n", data->map_cpy[i]);
	//controlla dopo il riempimento con le X che non ci siano piu collezionabili e uscite
	//ovvero che sono stati raccolti tutti o è stata raggiunta l'uscita
	check_values_map_cpy(data);
    return(1);
}
/*
int     pass_the_checks()
{

}
*/