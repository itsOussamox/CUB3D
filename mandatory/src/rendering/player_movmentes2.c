/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movmentes2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:11:25 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/20 13:28:41 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

int	key_press(int key, t_data *data)
{
	if (key == W)
		data->player.move_dir = 1;
	if (key == S)
		data->player.move_dir = -1;
	if (key == A)
		data->player.strafe_dir = -1;
	if (key == D)
		data->player.strafe_dir = 1;
	if (key == LEFT)
		data->player.turn_dir = -1;
	if (key == RIGHT)
		data->player.turn_dir = 1;
	if (key == M)
	{
		if (data->scale == 1)
			data->scale = SCALE;
		else
			data->scale = 1;
	}
	if (key == ESCAPE)
		end_game(data);
	return (1);
}
