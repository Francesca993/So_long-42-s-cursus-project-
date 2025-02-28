/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/28 17:19:13 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    check_image(t_matrix *data)
{
    if (!(data->textures.wall) || !(data->textures.grass)
            || !(data->textures.player_w) || !(data->textures.player_s)
            || !(data->textures.player_d) || !(data->textures.player_a)
            || !(data->textures.exit) || !(data->textures.bowl))
    {
        ft_printf("texture non caricate");
        close_window(data);
    }
}

void    open_image(t_matrix *data)
{
    load_player_sprites(data);
    data->textures.grass = mlx_xpm_file_to_image(data->mlx,
            "sprite_xpm/Grass.xpm", &data->textures.size, &data->textures.size);
    data->textures.wall = mlx_xpm_file_to_image(data->mlx,
            "sprite_xpm/wall.xpm copia", &data->textures.size, &data->textures.size);
    data->textures.player_w = mlx_xpm_file_to_image(data->mlx, 
            "sprite_xpm/player_w.xpm", &data->textures.size, &data->textures.size);
    data->textures.player_s = mlx_xpm_file_to_image(data->mlx,
            "sprite_xpm/player_s.xpm", &data->textures.size, &data->textures.size);
    data->textures.player_d = mlx_xpm_file_to_image(data->mlx,
            "sprite_xpm/player_d.xpm", &data->textures.size, &data->textures.size);
    data->textures.player_a = mlx_xpm_file_to_image(data->mlx,
            "sprite_xpm/player_a.xpm", &data->textures.size, &data->textures.size);
    data->textures.mouse = mlx_xpm_file_to_image(data->mlx,
            "sprite_xpm/mouse.xpm", &data->textures.size, &data->textures.size);
    data->textures.exit = mlx_xpm_file_to_image(data->mlx, 
            "sprite_xpm/cuccia.xpm", &data->textures.size, &data->textures.size);
    data->textures.bowl = mlx_xpm_file_to_image(data->mlx, 
            "sprite_xpm/food.xpm", &data->textures.size, &data->textures.size);
        /*

           if (!(data->textures.wall) || !(data->textures.grass) || !(data->textures.player_w) || !(data->textures.player_s) || !(data->textures.player_d) || !(data->textures.player_a) || !(data->textures.exit))
    {
        ft_printf("texture non caricate");
        close_window(data);
    }
        */
 
       check_image(data);
}

// W o Freccia Su
// S o Freccia Giù
// A o Freccia Sinistra
// D o Freccia Destra
void    print_player(t_matrix *data, int i, int index)
{
    if (data->keycode == 0)
        mlx_put_image_to_window(data->mlx, data->win, data->textures.player_a, i * TILE_SIZE, (index * TILE_SIZE));
    if (data->keycode == 119 || data->keycode == 65362)
        mlx_put_image_to_window(data->mlx, data->win, data->textures.player_w, i * TILE_SIZE, (index * TILE_SIZE));
    else if (data->keycode == 115 || data->keycode == 65364)
        mlx_put_image_to_window(data->mlx, data->win, data->textures.player_a, i * TILE_SIZE, (index * TILE_SIZE));
    else if (data->keycode == 97 || data->keycode == 65361)
        mlx_put_image_to_window(data->mlx, data->win, data->textures.player_s, i * TILE_SIZE, (index * TILE_SIZE));
    else if (data->keycode == 100 || data->keycode == 65363)
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
        else if(line[i] == 'N')
            mlx_put_image_to_window(data->mlx, data->win, data->an_enemy.enemy_frames[data->animation.current_frame], i * TILE_SIZE, (index * TILE_SIZE));
        else if(line[i] == 'A')
            mlx_put_image_to_window(data->mlx, data->win, data->animation.player_frames[data->animation.current_frame], i * TILE_SIZE, (index * TILE_SIZE));    
        i++;
        
    }
    
}