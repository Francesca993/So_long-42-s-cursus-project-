/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/19 13:43:00 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_matrix	*map_struct;
	int		rows;

	if (argc != 2)
	{
		ft_printf("Uso corretto: %s <nome_file>\n", argv[0]);
		return (1);
	}
	rows = ft_count_rows(argv[1]);
	map_struct = allocate_map(rows);
	fill_map(map_struct, argv[1]);
	check_map_rect(map_struct, rows);
	// Stampa la mappa per verifica
	ft_printf("Mappa caricata:\n");
	for (int i = 0; i < map_struct->rows; i++)
		printf("%s\n", map_struct->grid[i]);

	check_if_valid_path(map_struct);
	// Libera la memoria
	free_map(map_struct->grid, map_struct->rows);
	free(map_struct);
	return (0);
}

