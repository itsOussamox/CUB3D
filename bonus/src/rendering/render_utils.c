/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:33:35 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/12 19:42:28 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

static int	color_walls(t_data *data, int i, int xoff, int yoff)
{
	if (data->rays[i].angle > M_PI && data->rays[i].sym == 'H')
		return (get_south_texture(data, xoff, yoff));
	if (data->rays[i].angle < M_PI && data->rays[i].sym == 'H')
		return (get_north_texture(data, xoff, yoff));
	if ((data->rays[i].angle > M_PI / 2  &&
		data->rays[i].angle < M_PI + M_PI / 2) && data->rays[i].sym == 'V')
		return (get_east_texture(data, xoff, yoff));
	if ((data->rays[i].angle < M_PI / 2 || 
		data->rays[i].angle > M_PI + M_PI / 2) && data->rays[i].sym == 'V')
		return (get_west_texture(data, xoff, yoff));
	return (0);
}

int	get_wall_color(t_data *data, int i, int xoff, int yoff)
{
	if (data->rays[i].tab_hit == '1')
		return (color_walls(data, i, xoff, yoff));
	if (data->rays[i].tab_hit == '2')
		return (get_door_texture(data, xoff, yoff));
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

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				draw_rect(data, (j * data->minisize) ,
					(i * data->minisize) , WALL_COLOR);
			if (data->map[i][j] == '2')
				draw_rect(data, (j * data->minisize) ,
					(i * data->minisize) , DOOR_COLOR);
			if (data->map[i][j] == '0' || is_player(data->map[i][j]))
				draw_rect(data, (j * data->minisize) ,
					(i * data->minisize) , GROUND_COLOR);
			j++;
		}
		i++;
	}
}

void	render_2d(t_data *data)
{
	data->alpha = 50;
	data->minisize = floor(TILE_SIZE * data->scale);
	draw_map(data);
	put_player(data);
	render_rays(data);
	data->alpha = 0;
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