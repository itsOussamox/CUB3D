/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:32:58 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/09 17:04:40 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

double	get_wall_intercept(t_data *data, double xintercept, double yintercept, char sym)
{
	double	nextx;
	double	nexty;
	double	savex;
	double	savey;

	nextx = xintercept;
	nexty = yintercept;
	if (ray_out_of_map(data, nextx, nexty))
		return (LONG_MAX);
	while ((nextx > 0 || (int)nextx < data->map_width * data->minisize) &&
	(nexty > 0 || (int)nexty <= data->map_height * data->minisize))
	{
		savex = nextx;
		savey = nexty;
		if (intercept_wall(data, nextx, nexty))
			break;
		nextx += data->ray.xstep;
		nexty += data->ray.ystep;
		if (ray_out_of_map(data, nextx, nexty))
			return (LONG_MAX);
	}
	if (ray_out_of_map(data, nextx, nexty))
		return (LONG_MAX);
	set_wall_hit(data, savex, savey, sym);
	return (get_wall_distance(data, sym));
}

static double	horizontal_intersect(t_data *data, double rayangle)
{
	double	xintercept;
	double	yintercept;

	data->ray.ra = rayangle;
	yintercept = floor(data->player.y / data->minisize) * data->minisize;
	if (ray_facingdown(rayangle))
		yintercept += data->minisize;
	if (ray_facingup(rayangle))
		yintercept -= 0.0001;
	xintercept = data->player.x + ((yintercept - data->player.y) / tan(rayangle));
	data->ray.ystep = data->minisize;
	if (ray_facingup(rayangle))
		data->ray.ystep *= -1;
	data->ray.xstep = data->minisize / tan(rayangle);
	if (ray_facingleft(rayangle) && data->ray.xstep > 0)
		data->ray.xstep *= -1;
	if (ray_facingright(rayangle) && data->ray.xstep < 0)
		data->ray.xstep *= -1;
	return (get_wall_intercept(data, xintercept, yintercept, 'H'));
}

static double	vertical_intersect(t_data *data, double rayangle)
{
	double	xintercept;
	double	yintercept;

	xintercept = floor(data->player.x / data->minisize) * data->minisize;
	data->ray.ra = rayangle;
	if (ray_facingright(rayangle))
		xintercept += data->minisize;
	if (ray_facingleft(rayangle))
		xintercept -= 0.0001;
	yintercept = data->player.y + ((xintercept - data->player.x) * tan(rayangle));
	data->ray.xstep = data->minisize;
	if (ray_facingleft(rayangle))
		data->ray.xstep *= -1;
	data->ray.ystep = data->minisize * tan(rayangle);
	if (ray_facingup(rayangle) && data->ray.ystep > 0)
		data->ray.ystep *= -1;
	if (ray_facingdown(rayangle) && data->ray.ystep < 0)
		data->ray.ystep *= -1;
	return (get_wall_intercept(data, xintercept, yintercept, 'V'));
}

void	ray_cast(t_data *data, double rayangle, int i)
{
	double	walldistancev;	
	double	walldistanceh;

	walldistancev = vertical_intersect(data, rayangle);
	walldistanceh = horizontal_intersect(data, rayangle);
	if (walldistanceh < walldistancev)
	{
		data->rays[i].wallhity = data->ray.horzwallhity;
		data->rays[i].wallhitx = data->ray.horzwallhitx;
	}
	else
	{
		data->rays[i].wallhity = data->ray.vertwallhity;
		data->rays[i].wallhitx = data->ray.vertwallhitx;
	}
	data->rays[i].angle = rayangle;
	data->rays[i].distance = hypot(data->rays[i].wallhity - data->player.y, data->rays[i].wallhitx - data->player.x);
}

void	cast_rays(t_data *data)
{
	double	rayangle;
	int		i;

	data->numofrays = (data->map_width * (data->minisize));
	rayangle = data->player.pa - (FOV_ANGLE / 2);
	data->rays = malloc(data->numofrays * sizeof(t_rays));
	if (!data->rays)
		exit(1);
	i = 0;
	while (i < data->numofrays)
	{
		rayangle = fmod(rayangle, (2 * M_PI));
		if (rayangle < 0)
			rayangle += 2 * M_PI;
		if (rayangle == 0 || rayangle == M_PI)
			rayangle += 0.00000001;
		ray_cast(data, rayangle, i);
		rayangle += (FOV_ANGLE / data->numofrays);
		i++;
	}
}
