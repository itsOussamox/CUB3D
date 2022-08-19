/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:31:14 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/18 15:09:38 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

int	is_player(char c)
{
	if (c == 'S' || c == 'N' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

static void	set_player_angle(t_data *data, char pos)
{
	if (pos == 'N')
		data->player.pa = M_PI + M_PI / 2;
	if (pos == 'E')
		data->player.pa = 0;
	if (pos == 'S')
		data->player.pa = M_PI / 2;
	if (pos == 'W')
		data->player.pa = M_PI;
}

void	set_player(t_data *data, t_map_requirements *var)
{
	//printf("%d,%d\n",var->x_player,var->y_player - 6);
	data->player.x+= (var->x_player * data->minisize + data->minisize / 2);
	data->player.y =((var->y_player - 6)
			* data->minisize + data->minisize / 2);
	//printf("%f,%f, %d\n" ,data->player.x, data->player.y, data->minisize);
	set_player_angle(data, var->player_orientaition);
}

void	put_player(t_data *data)
{
	draw_player(data);
	draw_ray(data);
}
