/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/28 16:44:34 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Controlla se il nuovo movimento è valido (senza attraversare i muri)
void    move_player(t_matrix *data, int new_row, int new_col)
{
    
    if ((data->map[new_row][new_col] != '1') && (data->map[new_row][new_col] != 'A'))
    {
        if (data->map[new_row][new_col] == 'C')
        {
            data->map[data->position_p_row][data->position_p_col] = '0';
            data->colletionables--;
        }
        if (data->map[new_row][new_col] == 'E')
            exit_function(data, data->map[new_row][new_col]);
        if (data->map[new_row][new_col] == 'N')
            touch_enemy(data);
        ft_printf("Posizione attuale: %d, %d\n", data->position_p_row, data->position_p_col);
        data->map[data->position_p_row][data->position_p_col] = '0';    
        data->position_p_row = new_row;
        data->position_p_col = new_col;
        data->map[data->position_p_row][data->position_p_col] = 'P';
        data->count_moves++;
        ft_printf("Count moves: %d\n", data->count_moves);
        fill_window(data);
    }
}

// W o Freccia Su
// S o Freccia Giù
// A o Freccia Sinistra
// D o Freccia Destra
// ESC - Esci
int key_hook(int keycode, t_matrix *data)
{
    data->keycode = keycode;
    ft_printf("Tasto premuto: %d\n", keycode);
    if (keycode == 119 || keycode == 65362)
        move_player(data, data->position_p_row - 1, data->position_p_col);
    else if (keycode == 115 || keycode == 65364)
        move_player(data, data->position_p_row + 1, data->position_p_col);
    else if (keycode == 97 || keycode == 65361)
        move_player(data, data->position_p_row, data->position_p_col - 1);
    else if (keycode == 100 || keycode == 65363)
        move_player(data, data->position_p_row, data->position_p_col + 1);
    else if (keycode == 65307)
        close_window(data);
    return (0);
}