/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/28 17:31:21 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//funzioni per le animazioni dei personaggi
void load_player_sprites(t_matrix *data)
{
	data->animation.player_frames[0] = mlx_xpm_file_to_image(data->mlx, 
			"assets_bonus/three1.xpm", &data->textures.size,
			&data->textures.size);
	data->animation.player_frames[1] = mlx_xpm_file_to_image(data->mlx,
			"assets_bonus/three2.xpm", &data->textures.size, &data->textures.size);
	data->animation.player_frames[2] = mlx_xpm_file_to_image(data->mlx,
			"assets_bonus/three3.xpm", &data->textures.size, &data->textures.size);
	data->animation.player_frames[3] = mlx_xpm_file_to_image(data->mlx,
			"assets_bonus/three4.xpm", &data->textures.size,
			&data->textures.size);
	load_enemy(data);
	check_animation(data);
	data->animation.current_frame = 0;
}

void	load_enemy(t_matrix *data)
{
	data->an_enemy.enemy_frames[0] = mlx_xpm_file_to_image(data->mlx,
			"assets_bonus/dogl.xpm", &data->textures.size, &data->textures.size);
	data->an_enemy.enemy_frames[1] = mlx_xpm_file_to_image(data->mlx,
			"assets_bonus/dogr.xpm", &data->textures.size, &data->textures.size);
	data->an_enemy.enemy_frames[2] = mlx_xpm_file_to_image(data->mlx,
			"assets_bonus/dogl.xpm", &data->textures.size, &data->textures.size);
	data->an_enemy.enemy_frames[3] = mlx_xpm_file_to_image(data->mlx,
			"assets_bonus/dogr.xpm", &data->textures.size, &data->textures.size);
}

int	update_animation_enemy(t_matrix *data)
{
	static int	frame_delay_enemy;

	frame_delay_enemy = 0;
	frame_delay_enemy++;
	if (frame_delay_enemy >= 20)
	{
		data->an_enemy.current_frame = (
				data->an_enemy.current_frame + 1) % FRAME_COUNT;
		frame_delay_enemy = 0;
	}
	fill_window(data);
	return (0);
}
// Aggiorna l'animazione e ridisegna il frame corrente
// Regola la velocità dell'animazione
int update_animation(t_matrix *data)
{
	static int frame_delay = 0;

	frame_delay++;
	if (frame_delay >= 50)
	{
		data->animation.current_frame = (data->animation.current_frame + 1) % FRAME_COUNT;
		frame_delay = 0;
	}
	update_animation_enemy(data);
	fill_window(data);
	display_moves(data);
	return (0);
}

void display_moves(t_matrix *data)
{
	char *move_count;
	char *display_text;

	move_count = ft_itoa(data->count_moves);
	if (!move_count)
		return ;
	display_text = ft_strjoin("Movements: ", move_count);
	free(move_count);
	if (!display_text)
		return;
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

void touch_enemy(t_matrix *data)
{
		ft_putstr_fd("\nYou've touch an enemy!!\n", 1);
		ft_putstr_fd("Retry, maybe you will be lucky!\n", 1);
		close_window(data);
}
