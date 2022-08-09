/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:20:59 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/09 21:02:23 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	render_angle(t_data *data)
{
	data->minisize = TILE_SIZE;
	data->player.pa += data->player.turn_dir * ROTATION_SPEED;
	data->player.pa = fmod(data->player.pa, (2 * M_PI));
	if (data->player.pa < 0)
		data->player.pa += 2 * M_PI;
	if (data->player.pa == 0 || data->player.pa == M_PI)
		data->player.pa += 0.00000001;
}

double	player_move(t_data *data)
{
    double    newx;
    double    newy;
    int        x;
    int        y;

    if (!data->player.move_dir)
        return (1);
    newx = data->player.x + (cos(data->player.pa) * PLAYER_SPEED) * data->player.move_dir;
    newy = data->player.y + (sin(data->player.pa) * PLAYER_SPEED) * data->player.move_dir;
	// newx = get_strafe_x();
	// newy = get_strafe_y(data);
    y = floor(newy) / data->minisize;
    x = floor(newx) / data->minisize;
    if (data->map[y][x] >= '1' && ft_isdigit(data->map[y][x]))
        return (1);
    data->player.x = newx;
    data->player.y = newy;
    return (0);
}

int key_release(int key, t_data *data)
{
	if (key == W)
		data->player.move_dir = 0;
	if (key == S)
		data->player.move_dir = 0;
	if (key == A)
		data->player.strafe_dir = 0;
	if (key == D)
		data->player.strafe_dir = 0;
	if (key == LEFT)
		data->player.turn_dir = 0;
	if (key == RIGHT)
		data->player.turn_dir = 0;
	return (1);
}

int key_press(int key, t_data *data)
{
	if (key == W)
		data->player.move_dir = 1;
	if (key == S)
		data->player.move_dir = -1;
	if (key == A)
		data->player.strafe_dir = -1;
	if (key == D)
		data->player.strafe_dir = -1;
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