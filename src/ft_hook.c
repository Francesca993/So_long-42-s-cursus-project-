/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/28 14:19:23 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_player(t_matrix *data, int new_row, int new_col)
{
    // Controlla se il nuovo movimento è valido (senza attraversare i muri)
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
        ft_printf("Nuova posizione tentata: %d, %d\n", new_row, new_col);
        // Cancella la posizione precedente
        data->map[data->position_p_row][data->position_p_col] = '0';    
        // Aggiorna la posizione del giocatore
        data->position_p_row = new_row;
        data->position_p_col = new_col;
        data->map[data->position_p_row][data->position_p_col] = 'P';
        data->count_moves++;
        //display_moves(data); //mostra a schermo il conteggio delle mosse
        //stampo su shell il conteggio delle mosse
        ft_printf("Count moves: %d\n", data->count_moves);
        fill_window(data);
    }
}

int key_hook(int keycode, t_matrix *data)
{
    data->keycode = keycode;
    ft_printf("Tasto premuto: %d\n", keycode);
    if (keycode == 119 || keycode == 65362) // W o Freccia Su
        move_player(data, data->position_p_row - 1, data->position_p_col);
    else if (keycode == 115 || keycode == 65364) // S o Freccia Giù
        move_player(data, data->position_p_row + 1, data->position_p_col);
    else if (keycode == 97 || keycode == 65361) // A o Freccia Sinistra
        move_player(data, data->position_p_row, data->position_p_col - 1);
    else if (keycode == 100 || keycode == 65363) // D o Freccia Destra
        move_player(data, data->position_p_row, data->position_p_col + 1);
    else if (keycode == 65307) // ESC - Esci
        close_window(data);
    return (0);
}