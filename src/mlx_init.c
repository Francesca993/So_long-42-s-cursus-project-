/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/26 13:06:04 by fmontini         ###   ########.fr       */
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
    //dati->win = NULL;
    //free(data->mlx);
    //free(win);
	// Puoi anche chiamare free(mlx) se necessario
    }
    //exit(0);
     printf("Stopping mlx loop...\n");
    mlx_loop_end(data->mlx);// Esce dal loop senza terminare brutalmente
	exit(EXIT_SUCCESS);
    //mlx_loop_end(data->mlx);
    //return (0);
}

void    open_image(t_matrix *data)
{
    data->textures.grass = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/fmontini/Desktop/So_long/sprite_xpm/Grass.xpm", &data->textures.size, &data->textures.size);
    data->textures.wall = mlx_xpm_file_to_image(data->mlx, "/nfs/homes/fmontini/Desktop/So_long/sprite_xpm/wall.xpm copia", &data->textures.size, &data->textures.size);
    if (!((data->textures.wall) || (data->textures.wall)))
        ft_printf("texture non caricate");
}
void    print_map(char *line, t_matrix *data, int index)
{
    int     i;

    i = 0;
    while (line[i])
    {
        if ((line[i] == '1') || (line[i] == 'E') || (line[i] == 'P'))
        {
            mlx_put_image_to_window(data->mlx, data->win, data->textures.wall, i * TILE_SIZE, (index * TILE_SIZE));
        }
        else if (line[i] == '0' || (line[i] == 'C'))
        {
            mlx_put_image_to_window(data->mlx, data->win, data->textures.grass, i * TILE_SIZE, (index * TILE_SIZE));
        }
        i++;
    }
    
}

void    fill_window(t_matrix *data)
{
    int     i;

    i = 0;
    if(!(data->map))
    {
        ft_printf("errore nel caruicamento della mappa");
    }
    while(i < data->rows )
    {
        ft_printf("Stampo riga %d: %s\n", i, data->map[i]);
        print_map(data->map[i], data, i);
        i++;
    }
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
    open_image(data);
    fill_window(data);
          // 17 è il valore corrispondente all'evento DestroyNotify, che viene inviato quando l'utente clicca sulla "X" della finestra, 0 è la mask associata, che in questo caso non è necessaria per DestroyNotify.
    mlx_hook(data->win, 17, 0, close_window, data); 
    mlx_loop(data->mlx);
}