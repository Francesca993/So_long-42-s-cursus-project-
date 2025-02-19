/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_copy_map_from_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/19 14:41:56 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*copy_fd_tomap(t_matrix *map, char *line, int y, int fd)
{
	map->grid[y] = line;
	if (!map->grid[y])
	{
		free_map(map->grid, y);
		free(map);
		close(fd);
		return (NULL);
	}
	remove_new_line(map->grid[y]);
	return (line);
}

t_matrix	*fill_map(t_matrix *map, char *filedescriptor)
{
	char	*line;
	int		y;
	int		fd;

	y = 0;
	//line = NULL;
	fd = open(filedescriptor, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!line)
			return (NULL);
		line = copy_fd_tomap(map, line, y, fd);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

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
//copia la mappa in quella da utilizzare per flood fill
void    map_copy(t_matrix *map)
{
	int		i;

	map->map_cpy = (char **) malloc(sizeof(char *) * (map->rows + 1));
	if (map->map_cpy == NULL)
		ft_printf("Errore nell'allocazione della memoria nella copia della mappa");
	i = 0;
	while (i < map->rows)
	{
		map->map_cpy[i] = ft_strdup(map->grid[i]);
		i++;
	}
	map->map_cpy[i] = NULL;
}

void		count_cols(t_matrix *map)
{
	size_t	count;
	
	if (!map || !map->grid || !map->grid[0])
	{
    	ft_printf("Errore: mappa non valida o non inizializzata\n");
    	return ;
	}
	ft_printf("Lunghezza prima riga: %d\n", ft_strlen(map->grid[0]));
	count = (ft_strlen(map->grid[0]));
	map->cols = count;
	return ;
	
}