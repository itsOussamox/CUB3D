/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:23:22 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/20 13:38:06 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	data->img.addr[y * data->img.line_len + x] = color + (data->alpha << 24);
}

void	draw_line(t_data *data, double beginX, double beginY, double *tab)
{
	double	pixel_x;
	double	pixel_y;
	double	delta_x;
	double	deltay;
	int		pixels;

	deltay = tab[1] - beginY;
	delta_x = tab[0] - beginX;
	pixels = sqrt((delta_x * delta_x) + (deltay * deltay));
	delta_x /= pixels;
	deltay /= pixels;
	pixel_x = beginX;
	pixel_y = beginY;
	while (pixels)
	{
		my_mlx_pixel_put(data, pixel_x, pixel_y, 0xFF0000);
		pixel_x += delta_x;
		pixel_y += deltay;
		--pixels;
	}
}

void	draw_cursor(t_data *data)
{
	int	i;
	int	x;
	int	y;
	int	max;

	i = 0;
	y = data->window_height / 2;
	x = data->window_width / 2;
	max = 4;
	while (i < max)
	{
		my_mlx_pixel_put(data, x + i, y, PLAYER_COLOR);
		my_mlx_pixel_put(data, x, y + i, PLAYER_COLOR);
		my_mlx_pixel_put(data, x - i, y, PLAYER_COLOR);
		my_mlx_pixel_put(data, x, y - i, PLAYER_COLOR);
		i++;
	}
}
