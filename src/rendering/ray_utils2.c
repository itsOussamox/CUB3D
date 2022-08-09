/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:31:16 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/09 17:32:07 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

double	adjust_ray_y(t_data data, int y)
{
	if (y > data.map_height * data.minisize )
		y = data.map_height * data.minisize - 1;
	if (y < 0)
		y = 0;
	return (y);
}

double	adjust_ray_x(t_data data, int x)
{
	if (x > data.map_width * data.minisize)
		x = data.map_width * data.minisize;
	if (x < 0)
		x = 0;
	return (x);
}

int	intercept_wall(t_data *data, double x, double y)
{
	int	floorx;
	int	floory;

	floory = get_floor(y, *data);
	floorx = get_floor(x, *data);
	if (abs(floory) >= data->map_height || abs(floorx) >= (int)ft_strlen(data->map[floory]))
		return (1);
	if (data->map[abs(floory)][abs(floorx)] == '1')
		return (1);
	return (0);
}

int	get_floor(double x, t_data data)
{
	return (floor(x) / floor((data.minisize)));
}

double	get_wall_distance(t_data *data, char sym)
{
	double	distance;
	double	x1;
	double	x2;
	double	y1;
	double	y2;

	x1 = data->player.x;
	y1 = data->player.y;
	x2 = data->ray.horzwallhitx;
	y2 = data->ray.horzwallhity;
	if (sym == 'V')
		x2 = data->ray.vertwallhitx;
		y2 = data->ray.vertwallhity;
	// distance = sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) );
	distance = hypot(x2 - x1, y2 - y1);
	return (distance);
}