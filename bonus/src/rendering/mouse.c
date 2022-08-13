/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:02:18 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/13 13:19:11 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	get_mouse_data(t_data *data)
{
	int	x;
	int	y;

	if (!MOUSE_MOVE)
		return ;
	mlx_mouse_get_pos(data->win, &x, &y);
	if (x > data->mouse.mid_x)
		data->player.turn_dir = 1;
	if (x < data->mouse.mid_x)
		data->player.turn_dir = -1;
	if (x == data->mouse.mid_x)
		data->player.turn_dir = 0;
	mlx_mouse_move(data->win, data->window_width / 2, data->window_height / 2);
}
