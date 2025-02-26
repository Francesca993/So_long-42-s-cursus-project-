/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/26 16:32:59 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_player(t_matrix *game, int new_row, int new_col)
{
    // Controlla se il nuovo movimento è valido (senza attraversare i muri)
    if (game->map[new_row][new_col] != '1')
    {
        ft_printf("Posizione attuale: %d, %d\n", game->position_p_row, game->position_p_col);
        ft_printf("Nuova posizione tentata: %d, %d\n", new_row, new_col);
        // Cancella la posizione precedente
        game->map[game->position_p_row][game->position_p_col] = '0';
        
        // Aggiorna la posizione del giocatore
        game->position_p_row = new_row;
        game->position_p_col = new_col;
        game->map[game->position_p_row][game->position_p_col] = 'P';
        fill_window(game);

      /*
        // Disegna il giocatore nella nuova posizione
                mlx_put_image_to_window(game->mlx, game->win, game->textures.player_d, 
                                game->position_p_col * TILE_SIZE, game->position_p_row * TILE_SIZE);*/
    }
}
/*
int    move_player(t_matrix *game)
{
    int new_row = game->position_p_row - 1;
    int new_col = game->position_p_col;
        
     if (game->map[new_row][new_col] != '1')
    {
          // Cancella la posizione precedente
        game->map[game->position_p_row][game->position_p_col] = '0';
        game->position_p_row = new_row;
        game->position_p_col = new_col;
    }
    return (0);
    
}
*/

int key_hook(int keycode, t_matrix *data)
{
     ft_printf("Tasto premuto: %d\n", keycode);
    if (keycode == 119) // W - Su
        move_player(data, data->position_p_row - 1, data->position_p_col);    
    else if (keycode == 115) // S - Giù
        move_player(data, data->position_p_row + 1, data->position_p_col);
    else if (keycode == 97) // A - Sinistra
        move_player(data, data->position_p_row, data->position_p_col - 1);
    else if (keycode == 100) // D - Destra
        move_player(data, data->position_p_row, data->position_p_col + 1);
    else if (keycode == 65307) // ESC - Esci
        exit(0);

    return (0);
}

