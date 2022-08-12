/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:01:04 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/12 13:58:04 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

int	get_south_texture(t_data *data, int xoff, int yoff)
{
	return (data->so_data[(yoff * TILE_SIZE) + xoff]);
}
int	get_east_texture(t_data *data, int xoff, int yoff)
{
	return (data->ea_data[(yoff * TILE_SIZE) + xoff]);
}
int	get_west_texture(t_data *data, int xoff, int yoff)
{
	return (data->we_data[(yoff * TILE_SIZE) + xoff]);
}
int	get_north_texture(t_data *data, int xoff, int yoff)
{
	return (data->no_data[(yoff * TILE_SIZE) + xoff]);
}

int	get_door_texture(t_data *data, int xoff, int yoff)
{
	return (data->door_data[(yoff * TILE_SIZE) + xoff]);
}