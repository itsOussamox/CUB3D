/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:42:17 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/08 20:47:48 by obouadel         ###   ########.fr       */
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

void	draw_wall(t_data *data, t_rect rect, int color)
{
	int	i;
	int	j;

	i = rect.y;
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