/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/02/28 18:13:30 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_enemy(t_matrix *data)
{
	data->an_enemy.enemy_frames[0] = mlx_xpm_file_to_image(data->mlx, \
		"assets_bonus/dogl.xpm", &data->textures.size, \
			&data->textures.size);
	data->an_enemy.enemy_frames[1] = mlx_xpm_file_to_image(data->mlx,
			"assets_bonus/dogr.xpm",
			&data->textures.size, &data->textures.size);
	data->an_enemy.enemy_frames[2] = mlx_xpm_file_to_image(data->mlx,
			"assets_bonus/dogl.xpm",
			&data->textures.size, &data->textures.size);
	data->an_enemy.enemy_frames[3] = mlx_xpm_file_to_image(data->mlx,
			"assets_bonus/dogr.xpm",
			&data->textures.size, &data->textures.size);
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

void	touch_enemy(t_matrix *data)
{
	ft_putstr_fd("\nYou've touch an enemy!!\n", 1);
	ft_putstr_fd("Retry, maybe you will be lucky!\n", 1);
	close_window(data);
}
