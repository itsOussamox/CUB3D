/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:45:13 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/19 15:59:03 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	render_rays(t_data *data)
{
	int		i;
	double	tab[2];

	i = 0;
	while (i < data->numofrays)
	{
		tab[0] = data->rays[i].wallhitx * data->scale;
		tab[1] = data->rays[i].wallhity * data->scale;
		draw_line(data, (data->player.x * data->scale),
			(data->player.y * data->scale), tab);
		i++;
	}
}

void	render_3d(t_data *data, int i)
{
	double	raydistance;
	double	distance_pp;
	double	wallstrip_height;
	t_rect	rect;

	i = -1 ;
	mlx_clear_window(data->mlx, data->win);
	while (++i < data->numofrays)
	{
		raydistance = data->rays[i].distance
			* cos(data->rays[i].angle - data->player.pa);
		distance_pp = (data->window_width / 2) / fabs(tan(data->fov_angel / 2));
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
	}
	draw_cursor(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
}

void	ft_background_fill(t_data *data, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height * size)
	{
		j = 0;
		while (j < data->map_width * size)
		{
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}
