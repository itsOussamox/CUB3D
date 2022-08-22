/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:35:40 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/22 16:04:31 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"
#include "../../includes/parsing.h"

int	check_file(t_data *data)
{
	if (open(data->var->so, O_RDWR) == -1)
	{
		free_2d(data->var->map);
		free_file_path(data->var);
		return (1);
	}
	else if (open(data->var->no, O_RDWR) == -1)
	{
		free_2d(data->var->map);
		free_file_path(data->var);
		return (1);
	}
	if (check_file2(data) == 1)
		return (1);
	return (0);
}

int	check_file2(t_data *data)
{
	if (open(data->var->ea, O_RDWR) == -1)
	{
		free_2d(data->var->map);
		free_file_path(data->var);
		return (1);
	}
	else if (open(data->var->we, O_RDWR) == -1)
	{
		free_2d(data->var->map);
		free_file_path(data->var);
		return (1);
	}
	return (0);
}

void	init_offset(t_data *data, int *x_offset, int idx, int *max)
{
	if ((*max) >= data->window_height)
		(*max) = data->window_height;
	if (data->rays[idx].sym == 'V')
		(*x_offset) = (int)data->rays[idx].wallhity % TILE_SIZE;
	else
		(*x_offset) = (int)data->rays[idx].wallhitx % TILE_SIZE;
}

void	set_data2(t_data *data, t_map_requirements *var)
{
	data->player.move_dir = 0;
	data->player.turn_dir = 0;
	data->player.strafe_dir = 0;
	set_player(data, var);
	data->win = mlx_new_window(data->mlx, data->window_width,
			data->window_height, "Cub3D");
	if (data->win == NULL)
		ft_free(data, "Cant open window!");
	data->img.mlx_img = mlx_new_image(data->mlx,
			data->window_width, data->window_height);
	if (data->img.mlx_img == NULL)
		ft_free(data, "Cant open window!");
	data->img.addr = (int *)mlx_get_data_addr(data->img.mlx_img,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	data->img.line_len /= 4;
}
