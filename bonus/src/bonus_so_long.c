/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/03/01 15:00:09 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

int	main(int argc, char *argv[])
{
	t_matrix	*data;
	int			rows;

	if (argc != 2)
	{
		return (ft_printf("Uso corretto: %s <nome_file>\n", argv[0]), 1);
	}
	rows = ft_count_rows(argv[1]);
	data = allocate_map(rows);
	if (!(data))
		return (1);
	if (!(fill_map(data, argv[1])))
	{
		free_matrix(data);
		return (1);
	}
	ft_printf("Mappa caricata:\n");
	if (!(map_checks(data)))
	{
		free_matrix(data);
		return (1);
	}
	open_window(data);
	free_matrix(data);
	return (0);
}
