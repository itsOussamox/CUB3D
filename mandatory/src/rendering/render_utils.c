/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:33:35 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/20 13:39:59 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

static int	color_walls(t_data *data, int i, int xoff, int yoff)
{
	if (data->rays[i].angle > M_PI && data->rays[i].sym == 'H')
		return (get_south_texture(data, xoff, yoff));
	if (data->rays[i].angle < M_PI && data->rays[i].sym == 'H')
		return (get_north_texture(data, xoff, yoff));
	if ((data->rays[i].angle > M_PI / 2
			&& data->rays[i].angle < M_PI + M_PI / 2)
		&& data->rays[i].sym == 'V')
		return (get_east_texture(data, xoff, yoff));
	if ((data->rays[i].angle < M_PI / 2
			|| data->rays[i].angle > M_PI + M_PI / 2)
		&& data->rays[i].sym == 'V')
		return (get_west_texture(data, xoff, yoff));
	return (0);
}

int	get_wall_color(t_data *data, int i, int xoff, int yoff)
{
	if (data->rays[i].tab_hit == '1')
		return (color_walls(data, i, xoff, yoff));
	printf("cant find");
	return (0x330906);
}

void	set_wall_hit(t_data *data, double x, double y, char sym)
{
	if (sym == 'V')
	{
		data->ray.vertwallhity = y;
		data->ray.vertwallhitx = x;
	}
	if (sym == 'H')
	{
		data->ray.horzwallhity = y;
		data->ray.horzwallhitx = x;
	}
}
