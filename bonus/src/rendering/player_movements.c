/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:20:59 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/18 13:39:07 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	open_door(t_data *data)
{
	static double	counter;
	int				i;
	static int		x;
	static int		y;

	i = data->numofrays / 2;
	if (counter)
		counter++;
	if (counter == 150)
	{
		data->map[y][x] = '2';
		counter = 0;
	}
	if (data->player.open_door == 0)
		return ;
	if (data->rays[i].tab_hit == '2'
		&& data->rays[i].distance <= 45)
	{
		ft_playsound(2);
		x = floor(data->rays[i].wallhitx) / data->minisize;
		y = floor(data->rays[i].wallhity) / data->minisize;
		data->map[y][x] = '0';
		counter = 1;
	}
	data->player.open_door = 0;
}

//if player turns update the angle that he's facing
void	render_angle(t_data *data)
{
	data->minisize = TILE_SIZE;
	data->player.pa += data->player.turn_dir * ROTATION_SPEED;
	data->player.pa = fmod(data->player.pa, (2 * (M_PI)));
	if (data->player.pa < 0) //keep the player angle in the range of 0 to 2*pie
		data->player.pa += 2 * M_PI;
	if (data->player.pa == 0 || data->player.pa == M_PI)
		data->player.pa += 0.00000001;
}

void	player_strafe(t_data *data)
{
	double	temp_angle;
	double	newx;
	double	newy;
	int		x;
	int		y;

	if (data->player.strafe_dir == 0)
		return ;
	if (data->player.strafe_dir == -1)
		temp_angle = data->player.pa - (M_PI_2);
	else
		temp_angle = data->player.pa + (M_PI_2);
	newx = data->player.x + (cos(temp_angle) * (PLAYER_STRAFE));
	newy = data->player.y + (sin(temp_angle) * (PLAYER_STRAFE));
	x = floor(data->player.x) / data->minisize;
	y = floor(newy) / data->minisize;
	if (data->map[y][x] == '0' || data->map[y][x]
			== data->var->player_orientaition)
		data->player.y = newy;
	y = floor(data->player.y) / data->minisize;
	x = floor(newx) / data->minisize;
	if (data->map[y][x] == '0' || data->map[y][x]
			== data->var->player_orientaition)
		data->player.x = newx;
}

void	player_move(t_data *data)
{
	double		newx;
	double		newy;
	int			x;
	int			y;

	if (!data->player.move_dir)
		return ;
	newx = data->player.x + (cos(data->player.pa) * PLAYER_SPEED)
		* data->player.move_dir;
	newy = data->player.y + (sin(data->player.pa) * PLAYER_SPEED)
		* data->player.move_dir;
	x = floor(data->player.x) / data->minisize;
	y = floor(newy) / data->minisize;
	if (data->map[y][x] == '0' || data->map[y][x]
			== data->var->player_orientaition)
		data->player.y = newy;
	y = floor(data->player.y) / data->minisize;
	x = floor(newx) / data->minisize;
	if (data->map[y][x] == '0' || data->map[y][x]
			== data->var->player_orientaition)
		data->player.x = newx;
}

int	key_release(int key, t_data *data)
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
