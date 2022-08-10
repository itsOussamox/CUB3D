/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:17:21 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/08 23:22:50 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

int	ray_out_of_map(t_data *data, double x, double y)
{
	if (x < 0 || x >= data->map_width * data->minisize)
		return (1);
	if (y < 0 || y >= data->map_height * data->minisize)
		return (1);
	return (0);
}

int	ray_facingright(double angle)
{
	if (angle < M_PI_2 || angle > 1.5 * M_PI)
		return (1);
	return (0);	
}

int	ray_facingleft(double angle)
{
	if (!ray_facingright(angle))
		return (1);
	return (0);	
}

int	ray_facingdown(double angle)
{
	if (angle > 0 && angle < M_PI)
		return (1);
	return (0);	
}

int	ray_facingup(double angle)
{
	if (!ray_facingdown(angle))
		return (1);
	return (0);	
}