/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/26 12:24:57 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_matrix	*data;
	int		rows;

	if (argc != 2)
	{
		ft_printf("Uso corretto: %s <nome_file>\n", argv[0]);
		return (1);
	}
	rows = ft_count_rows(argv[1]);
	data = allocate_map(rows);
	if(!(data))
		return (1);
	if(!(fill_map(data, argv[1])))
	{
		free_matrix(data);
		return (1);
	}
	// Stampa la mappa per verifica
	ft_printf("Mappa caricata:\n");
	for (int i = 0; i < data->rows; i++)
		printf("%s\n", data->map[i]);
	if(!(map_checks(data)))
	{
		free_matrix(data);
		return (1);
	}
	open_window(data);
	// Libera la memoria
	free_matrix(data);
	return (0);
}

