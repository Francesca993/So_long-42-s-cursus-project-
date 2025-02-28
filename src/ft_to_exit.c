/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/28 14:50:01 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_textures(t_matrix *data)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while ( i < FRAME_COUNT)
    {
        if (data->animation.player_frames[i])
            mlx_destroy_image(data->mlx, data->animation.player_frames[i]);
        i++;
    }
    while ( j < FRAME_COUNT)
    {
        if (data->an_enemy.enemy_frames[j])
            mlx_destroy_image(data->mlx, data->an_enemy.enemy_frames[j]);
        j++;
    }
    if (data->textures.wall)
        mlx_destroy_image(data->mlx, data->textures.wall);
    if (data->textures.grass)
        mlx_destroy_image(data->mlx, data->textures.grass);
    if (data->textures.player_w)
        mlx_destroy_image(data->mlx, data->textures.player_w);
    if (data->textures.player_s)
        mlx_destroy_image(data->mlx, data->textures.player_s);
    if (data->textures.player_d)
        mlx_destroy_image(data->mlx, data->textures.player_d);
    if (data->textures.player_a)
        mlx_destroy_image(data->mlx, data->textures.player_a);
    if (data->textures.mouse)
        mlx_destroy_image(data->mlx, data->textures.mouse);
    if (data->textures.exit)
        mlx_destroy_image(data->mlx, data->textures.exit);
    if (data->textures.bowl)
        mlx_destroy_image(data->mlx, data->textures.bowl);
}

int	close_window(t_matrix *data)
{
    if (data->mlx && data->win)
    {
        free_textures(data);
        printf("Closing window..\n");
	    mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
    }
    printf("Stopping mlx loop...\n");
    mlx_loop_end(data->mlx);
    free_matrix(data);
	exit(EXIT_SUCCESS);
}

void    exit_function(t_matrix *data, char new_pos)
{
    if (new_pos == 'E' && data->colletionables == 0)
	{
		ft_putstr_fd("\nYou fell into the BlackHole!\n", 1);
		ft_putstr_fd("Enjoy the rest of your life in the void!\n", 1);
		close_window(data);
	}
    else if(new_pos == 'E' && data->colletionables > 0)
    {
        ft_printf("Hai perso! Non hai raccolto tutti i collezionabili!\n");
        close_window(data);
    }
}