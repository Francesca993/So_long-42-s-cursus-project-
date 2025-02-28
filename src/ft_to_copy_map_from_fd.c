/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_copy_map_from_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/28 16:04:03 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*copy_fd_tomap(t_matrix *map, char *line, int y, int fd)
{
	map->map[y] = line;
	if (!map->map[y])
	{
		free_map(map->map, y);
		free(map);
		close(fd);
		return (NULL);
	}
	remove_new_line(map->map[y]);
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
		/*
		if (!line)		
			return (NULL);
		line = copy_fd_tomap(map, line, y, fd);
		y++;
		line = get_next_line(fd);
		*/
		if(!copy_fd_tomap(map, line, y, fd))
		{
			close(fd);
			return(NULL);
		}
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

	map->map_cpy = (char **)ft_calloc((map->rows + 1), sizeof(char *));
	if (!(map->map_cpy))
		return ;
	i = 0;
	while (i < map->rows)
	{
		map->map_cpy[i] = ft_strdup(map->map[i]);
		if (!(map->map_cpy[i]))
		{
			while (i >= 0)
			{
				i--;
				free(map->map_cpy[i]);
			}
			free(map->map_cpy);
			map->map_cpy = NULL;
			ft_printf("errore nell'allocazione della mem. della copia della mappa");
			return ;
		}
		i++;
	}
	map->map_cpy[i] = NULL;
}

void		count_cols(t_matrix *map)
{
	size_t	count;
	
	if (!map || !map->map || !map->map[0])
	{
    	ft_printf("Errore: mappa non valida o non inizializzata\n");
    	return ;
	}
	count = (ft_strlen(map->map[0]));
	map->cols = count;
	return ;
}