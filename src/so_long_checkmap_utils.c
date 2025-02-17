/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checkmap_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/17 16:03:40 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int remove_new_line(char *str)
{
    int count;
    
    if(!str)
        return(0);

    count = ft_strlen(str);
    if ((count > 0) && (str[count -1] == '\n'))
    {
        str[count -1] = '\0';
    }

    return (1);
}

int check_map_rect(t_matrix *map_struct, int rows)
{
    int y;
    int len;

    y = 0;
    if (rows <= 0)
        return (0);
    len = (int)ft_strlen(map_struct->grid[0]);
    while (y < rows)
    {
        if(((int)ft_strlen(map_struct->grid[y])) != len)
         {
            printf("Errore: le righe della mappa non sono tutte uguali!\n");
            return (0);
        }
        y++;
    }
    if ( len == rows)
    {
        printf("Errore: la mappa non è rettangolare.\n");
        return (0);
    }
    printf("Le righe della mappa sono tutte uguali ed è rettangolare.\n");
    return (1);
}