/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/17 13:06:51 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_matrix	*map_struct;
	int		rows;

	if (argc != 2)
	{
		printf("Uso corretto: %s <nome_file>\n", argv[0]);
		return (1);
	}
	rows = ft_count_rows(argv[1]);
	map_struct = allocate_map(rows);
	fill_map(map_struct, argv[1]);
	// Stampa la mappa per verifica
	printf("Mappa caricata:\n");
	for (int i = 0; i < map_struct->rows; i++)
		printf("%s", map_struct->grid[i]);

	// Libera la memoria
	free_map(map_struct->grid, map_struct->rows);
	free(map_struct);
	return (0);
}

