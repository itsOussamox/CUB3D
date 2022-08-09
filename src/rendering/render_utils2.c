/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:45:13 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/09 22:14:34 by obouadel         ###   ########.fr       */
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
		draw_wall(data, rect, get_wall_color(data, i));
		draw_bot(data, rect);
		data->alpha = 0;
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.addr, 0, 0);
} 