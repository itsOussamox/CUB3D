/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:45:13 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/09 17:38:04 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	render_rays(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numofrays)
	{
		draw_line(data, (data->player.x * data->scale), (data->player.y * data->scale),
			(data->rays[i].wallhitx * data->scale),
			(data->rays[i].wallhity * data->scale));
		i++;
	}
}

void	render_3d(t_data *data)
{
	int		i;
	double	raydistance;
	double	distance_pp;
	double	wallstrip_height;
	t_rect	rect;

	i = 0 ;
	// ft_background_fill(data, data->minisize, 0x212121);
	mlx_clear_window(data->mlx, data->win);
	while (i < data->numofrays)
	{
		raydistance = data->rays[i].distance * cos(data->rays[i].angle - data->player.pa);
		distance_pp = (data->window_width / 2) / fabs(tan(FOV_ANGLE / 2));
		wallstrip_height = (TILE_SIZE / raydistance) * distance_pp;
		if (wallstrip_height > data->window_height)
			wallstrip_height = data->window_height - 1;
		rect = get_rect(i * WSTRIP, (data->window_height / 2)
		 - (wallstrip_height / 2), WSTRIP, wallstrip_height);
		draw_top(data, rect);
		data->alpha = raydistance / 10;
		if (data->alpha > 100)
			data->alpha = 100;
		draw_wall(data, rect, 0xb4b4b4);
		data->alpha = 0;
		draw_bot(data, rect);
		i++;
	}
	// int	line_height;
	// int	draw_start;
	// int	draw_end;
	// t_rect	rect;
	// // printf("numofrays = [%d]\n", data->numofrays);
	// while (i < data->numofrays)
	// {
	// 	line_height = (int)(data->window_height / data->rays_distance[i]);
	// 	draw_start = -line_height / 2 + data->window_height / 2;
	// 	if (draw_start < 0)
	// 		draw_start = 0;
	// 	draw_end = line_height / 2 + data->window_height / 2;
	// 	if (draw_end >= data->window_height)
	// 		draw_end = data->window_height - 1;
	// 	rect =s get_rect(i, draw_start, i, draw_end);
	// 	draw_wall(data, rect, 0xFFFFFF);
	// 	i++;
	// }
	mlx_put_image_to_window(data->mlx, data->win, data->img.addr, 0, 0);
} 