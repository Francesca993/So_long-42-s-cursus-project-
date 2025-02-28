/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/28 17:09:58 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    fill_window(t_matrix *data)
{
    int     i;

    i = 0;
    if(!(data->map))
    {
        ft_printf("errore nel caruicamento della mappa");
        return (0);
    }
    while(i < data->rows )
    {
        print_map(data->map[i], data, i);
        i++;
    }
    return (0);
}

// 17 è il valore corrispondente all'evento DestroyNotify, che viene inviato quando 
//l'utente clicca sulla "X" della finestra, 0 è la mask associata, 
//che in questo caso non è necessaria per DestroyNotify.
void open_window(t_matrix *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
    {
        ft_printf("Fallita inizializzazione di mlx");
        return ;
    }
    data->win = mlx_new_window(data->mlx, TILE_SIZE * data->cols, TILE_SIZE * data->rows, "So Long");
    if (!data->win)
    {
        ft_printf("mlx_new_window failed.");
        return ;   
    }
    data->count_moves = 0;
    open_image(data);
    mlx_hook(data->win, 2, 1L<<0, key_hook, data);
    fill_window(data);
    mlx_loop_hook(data->mlx, (int (*)(void *))update_animation, data);
    mlx_hook(data->win, 17, 0, close_window, data); 
    mlx_loop(data->mlx);
}

