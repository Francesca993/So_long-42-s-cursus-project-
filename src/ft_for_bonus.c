/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/27 14:42:15 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//#define FRAME_COUNT 4  // Numero di frame dell'animazione
/*
typedef struct s_animation {
    void    *player_frames[FRAME_COUNT];  // Array di frame del personaggio
    int     current_frame;
    int     x;
    int     y;
}   t_animation;
*/

//funzioni per le animazioni dei personaggi

void load_player_sprites(t_matrix *data)
{
    data->animation.player_frames[0] = mlx_xpm_file_to_image(data->mlx, "assets_bonus/three1.xpm", &data->textures.size, &data->textures.size);
    data->animation.player_frames[1] = mlx_xpm_file_to_image(data->mlx, "assets_bonus/three2.xpm", &data->textures.size, &data->textures.size);
    data->animation.player_frames[2] = mlx_xpm_file_to_image(data->mlx, "assets_bonus/three3.xpm", &data->textures.size, &data->textures.size);
    data->animation.player_frames[3] = mlx_xpm_file_to_image(data->mlx, "assets_bonus/three4.xpm", &data->textures.size, &data->textures.size);
    data->animation.current_frame = 0;
}
// Aggiorna l'animazione e ridisegna il frame corrente
int update_animation(t_matrix *data)
{
    static int frame_delay = 0;

    frame_delay++;
    if (frame_delay >= 50) // Regola la velocità dell'animazione
    {
        data->animation.current_frame = (data->animation.current_frame + 1) % FRAME_COUNT;
        frame_delay = 0;
    }
    /*
    mlx_put_image_to_window(data->mlx, data->win, 
        data->animation.player_frames[data->animation.current_frame], 
        data->animation.x, data->animation.y);
    */
    // mlx_put_image_to_window(data->mlx, data->win, data->animation.player_frames[data->animation.current_frame], i * TILE_SIZE, (index * TILE_SIZE));
    fill_window(data);
    display_moves(data);
    return (0);
}

/*
Nel main(), dopo aver caricato le immagini, collega la funzione update_animation() al loop principale:

int main(void)
{
    t_data data;
    int width, height;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 800, 600, "So Long Animation");
    data.x = 100;
    data.y = 100;

    load_player_sprites(&data);

    mlx_loop_hook(data.mlx, update_animation, &data);
    mlx_loop(data.mlx);

    return (0);
}
*/

//funzioni per visualizzare il count a schermo

void display_moves(t_matrix *data)
{
    char *move_count;
    char *display_text; // Stringa per il numero di movimenti

    move_count = ft_itoa(data->count_moves);
    if (!move_count)
        return ;
    // Concatenare il testo con il numero
    display_text = ft_strjoin("Movements: ", move_count);
    free(move_count);  // Libera la memoria della stringa convertita
    if (!display_text)
        return;
/*
    Pulire la finestra per evitare sovrapposizioni
    mlx_clear_window(data->mlx, data->win);
    // Ridisegnare il personaggio dopo la pulizia
    mlx_put_image_to_window(data->mlx, data->win, data->player_img, data->player_x, data->player_y);
*/
    // Mostrare il testo con il conteggio dei movimenti
    //mlx_clear_window(data->mlx, data->win);
    int i=0, j=0;
    while (i < 30)
    {
        j = 0;
        while (j < 100)
        {
            mlx_pixel_put(data->mlx, data->win, j, i, 0x000000);
            j++;
        }
        i++;
    }
    
    mlx_string_put(data->mlx, data->win, 10, 15, 0xCC0000, display_text);

    free(display_text); 
}
//funzioni per l'uscita se tocca un nemico

void touch_enemy(t_matrix *data)
{
		ft_putstr_fd("\nYou've touch an enemy!!\n", 1);
		ft_putstr_fd("Retry, maybe you will be lucky!\n", 1);
        close_window(data);
}