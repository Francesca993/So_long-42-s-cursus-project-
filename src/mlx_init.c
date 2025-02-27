/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/27 14:49:19 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_matrix *data)
{
    if (data->mlx && data->win)
    {
        printf("Closing window..\n");
	    mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
    }
    printf("Stopping mlx loop...\n");
    mlx_loop_end(data->mlx);
	exit(EXIT_SUCCESS);
}

void    open_image(t_matrix *data)
{
    load_player_sprites(data);
    data->textures.grass = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/fmontini/Desktop/So_long/sprite_xpm/Grass.xpm", &data->textures.size, &data->textures.size);
    data->textures.wall = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/fmontini/Desktop/So_long/sprite_xpm/wall.xpm copia", &data->textures.size, &data->textures.size);
    data->textures.player_w = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/fmontini/Desktop/So_long/sprite_xpm/player_w.xpm", &data->textures.size, &data->textures.size);
    data->textures.player_s = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/fmontini/Desktop/So_long/sprite_xpm/player_s.xpm", &data->textures.size, &data->textures.size);
    data->textures.player_d = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/fmontini/Desktop/So_long/sprite_xpm/player_d.xpm", &data->textures.size, &data->textures.size);
    data->textures.player_a = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/fmontini/Desktop/So_long/sprite_xpm/player_a.xpm", &data->textures.size, &data->textures.size);
    data->textures.mouse = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/fmontini/Desktop/So_long/sprite_xpm/mouse.xpm", &data->textures.size, &data->textures.size);
    data->textures.exit = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/fmontini/Desktop/So_long/sprite_xpm/cuccia.xpm", &data->textures.size, &data->textures.size);
    data->textures.bowl = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/fmontini/Desktop/So_long/sprite_xpm/food.xpm", &data->textures.size, &data->textures.size);
    
    if (!((data->textures.wall) || (data->textures.grass)))
        ft_printf("texture non caricate");
}

void    print_player(t_matrix *data, int i, int index)
{
    if (data->keycode == 0)
        mlx_put_image_to_window(data->mlx, data->win, data->textures.player_a, i * TILE_SIZE, (index * TILE_SIZE));
    if (data->keycode == 119 || data->keycode == 65362) // W o Freccia Su
        mlx_put_image_to_window(data->mlx, data->win, data->textures.player_w, i * TILE_SIZE, (index * TILE_SIZE));
    else if (data->keycode == 115 || data->keycode == 65364) // S o Freccia Giù
        mlx_put_image_to_window(data->mlx, data->win, data->textures.player_a, i * TILE_SIZE, (index * TILE_SIZE));
    else if (data->keycode == 97 || data->keycode == 65361) // A o Freccia Sinistra
        mlx_put_image_to_window(data->mlx, data->win, data->textures.player_s, i * TILE_SIZE, (index * TILE_SIZE));
    else if (data->keycode == 100 || data->keycode == 65363) // D o Freccia Destra
        mlx_put_image_to_window(data->mlx, data->win, data->textures.player_d, i * TILE_SIZE, (index * TILE_SIZE));
}

void    print_map(char *line, t_matrix *data, int index)
{
    int     i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '1')
            mlx_put_image_to_window(data->mlx, data->win, data->textures.wall, i * TILE_SIZE, (index * TILE_SIZE));
        else if (line[i] == '0')
            mlx_put_image_to_window(data->mlx, data->win, data->textures.grass, i * TILE_SIZE, (index * TILE_SIZE));
        else if(line[i] == 'P')
            print_player(data, i, index);
        else if(line[i] == 'E')
            mlx_put_image_to_window(data->mlx, data->win, data->textures.exit, i * TILE_SIZE, (index * TILE_SIZE));
        else if(line[i] == 'C')
            mlx_put_image_to_window(data->mlx, data->win, data->textures.bowl, i * TILE_SIZE, (index * TILE_SIZE));
        //else if(line[i] == 'N')          
        else if(line[i] == 'A')
            mlx_put_image_to_window(data->mlx, data->win, data->animation.player_frames[data->animation.current_frame], i * TILE_SIZE, (index * TILE_SIZE));

            
        i++;
        
    }
    
}

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
        ft_printf("Stampo riga %d: %s\n", i, data->map[i]);
        print_map(data->map[i], data, i);
        i++;
    }
    return (0);
}


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
    //mlx_key_hook(data->win, key_hook, &data);
    mlx_hook(data->win, 2, 1L<<0, key_hook, data);
    fill_window(data);
    //mlx_loop_hook(data->mlx, fill_window, data);
    mlx_loop_hook(data->mlx, (int (*)(void *))update_animation, data);

    // 17 è il valore corrispondente all'evento DestroyNotify, che viene inviato quando l'utente clicca sulla "X" della finestra, 0 è la mask associata, che in questo caso non è necessaria per DestroyNotify.
    mlx_hook(data->win, 17, 0, close_window, data); 
    mlx_loop(data->mlx);
}