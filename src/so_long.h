/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:44:27 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/19 16:12:15 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Include le librerie
# include <stdio.h>    // Per printf, perror, etc.
# include <stdlib.h>   // Per malloc, free, exit, etc.
# include <unistd.h>   // Per read, write, close, etc.
# include <fcntl.h>    // Per open()
# include "../Libft/libft.h"         // Include le funzioni della libft
# include "../minilibx/mlx.h"        // Include la libreria grafica MiniLibX
# include "../Printf/ft_printf.h"         // Include le funzioni della libft

// Definisci strutture utili per il gioco
typedef struct s_matrix
{
	char	**grid;
	int		rows;
	int		cols;
	char	**map_cpy;
	int     position_p_row;
    int     position_p_col;
}	t_matrix;

// Prototipi delle funzioni principali
void		free_map(char **map, int rows);
void		free_matrix(t_matrix *map_struct);
t_matrix	*allocate_map(int rows);
t_matrix	*fill_map(t_matrix *map, char *filedescriptor);
int			ft_count_rows(char *filename);
void		free_matrix(t_matrix *map_struct);
int			remove_new_line(char *str);
int			check_map_rect(t_matrix *map_struct, int rows);
int			check_map_walls(t_matrix *map_struct, int rows);
int			check_map_walls_x(t_matrix *map_struct, int rows);
char		*copy_fd_tomap(t_matrix *map, char *line, int y, int fd);
void		map_copy(t_matrix *map);
void		flood_fill(t_matrix *map, int row, int col);
void		check_values_map_cpy(t_matrix *map);
void		find_position_p(t_matrix *map);
int			count_p_e(t_matrix	*map);
void		count_cols(t_matrix *map);
int			check_if_valid_path(t_matrix *data);

#endif