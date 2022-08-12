/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:45:13 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/12 16:45:13 by obouadel         ###   ########.fr       */
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
		rect = get_rect(i, (data->window_height / 2)
		 - (wallstrip_height / 2), 1, wallstrip_height); 
		draw_top(data, rect);
		data->alpha = raydistance / 6;
		if (data->alpha > 250)
			data->alpha = 250;
		draw_wall(data, rect, i);
		draw_bot(data, rect);
		data->alpha = 0;
		i++;
	}
	draw_cursor(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.addr, 0, 0);
} 