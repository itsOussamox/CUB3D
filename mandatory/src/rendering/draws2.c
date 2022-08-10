/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:42:17 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/09 18:11:00 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

t_rect	get_rect(int x, int y, int dx, int dy)
{
	t_rect	newrect;

	newrect.y = y;
	newrect.x = x;
	newrect.dx = dx;
	newrect.dy = dy;
	return (newrect);
}

void	draw_rect(t_data *data, int rectx, int recty, int color)
{
	int	i;
	int	j;
	int	tile;

	tile = data->minisize - GRID;
	i = recty;
	while (i < recty + tile)
	{
		j = rectx;
		while (j < rectx + tile)
			my_mlx_pixel_put(data, j++, i, color);
		++i;
	}
}

void	draw_bot(t_data *data, t_rect a)
{
	int	y;
	int	x;

	y = a.y + a.dy;
	while (y < data->window_height)
	{
		data->alpha -= 1;
		if (data->alpha < 0)
			data->alpha = 0;
		x = a.x;
		// data->alpha = x - (data->window_height / 2);
		while (x < a.x + a.dx)
			my_mlx_pixel_put(data, x++, y, data->f_color);
		// data->alpha--;
		y++;
	}
}

void	draw_top(t_data *data, t_rect a)
{
	int	y;
	int	x;

	y = 0;
	while (y < a.y)
	{
		x = a.x;
		while (x < a.x + a.dx)
			my_mlx_pixel_put(data, x++, y, data->c_color);
		y++;
	}
}

void	draw_wall(t_data *data, t_rect rect, int color)
{
	int	i;
	int	j;
	int	z;

	i = rect.y;
	z = 0;
	while (i < rect.y + rect.dy)
	{
		j = rect.x;
		while (j < rect.x + rect.dx)
		{
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		++i;
	}
}