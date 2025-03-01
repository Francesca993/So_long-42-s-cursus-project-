/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ft_enemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontini <fmontini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:49:36 by fmontini          #+#    #+#             */
/*   Updated: 2025/03/01 13:25:29 by fmontini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

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

void	count_enemy(t_matrix *map)
{
	int		y;
	int		n;
	int		x;

	n = 0;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->map[y][x] == 'N')
			{
				map->an_enemy.x = x;
				map->an_enemy.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

// Cambia direzione a destra
void	enemy_come_back(t_matrix *data)
{
	if ((data->map[data->an_enemy.y][data->an_enemy.x - 1] != '1') &&
		(data->map[data->an_enemy.y][data->an_enemy.x - 1] != 'A') &&
		(data->map[data->an_enemy.y][data->an_enemy.x - 1] != 'C') &&
		(data->map[data->an_enemy.y][data->an_enemy.x - 1] != 'E'))
	{
		data->map[data->an_enemy.y][data->an_enemy.x] = '0';
		data->an_enemy.x = data->an_enemy.x - 1;
		data->map[data->an_enemy.y][data->an_enemy.x] = 'N';
		fill_window(data);
	}
	else
		data->an_enemy.dir = 1;
}

// Se sta andando a destra
// Cambia direzione a sinistra
// Se sta andando a sinistra
void	move_enemy(t_matrix *data)
{
	ft_printf("Posizione attuale nemico");
	ft_printf(": %d, %d\n", data->an_enemy.y, data->an_enemy.x);
	if (data->an_enemy.dir == 1)
	{
		if ((data->map[data->an_enemy.y][data->an_enemy.x + 1] != '1') &&
			(data->map[data->an_enemy.y][data->an_enemy.x + 1] != 'A') &&
			(data->map[data->an_enemy.y][data->an_enemy.x + 1] != 'C') &&
			(data->map[data->an_enemy.y][data->an_enemy.x + 1] != 'E'))
		{
			data->map[data->an_enemy.y][data->an_enemy.x] = '0';
			data->an_enemy.x = data->an_enemy.x + 1;
			data->map[data->an_enemy.y][data->an_enemy.x] = 'N';
			fill_window(data);
		}
		else
			data->an_enemy.dir = -1;
	}
	else if (data->an_enemy.dir == -1)
	{
		enemy_come_back(data);
	}
}
