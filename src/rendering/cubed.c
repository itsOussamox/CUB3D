/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:54 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/08 23:08:00 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

int	game_render(t_data *data)
{
	render_angle(data);
	player_move(data);
	cast_rays(data);
	render_3d(data);
	render_2d(data);
	free(data->rays);
	return (1);
}


static void set_data(t_data *data, t_map_requirements *var)
{
	data->map_height = var->height;
	data->map_width = 35;
	data->window_width = TILE_SIZE * data->map_width;
	data->window_height = TILE_SIZE * data->map_height;
	data->minisize = TILE_SIZE;
	data->map = var->map + 6;
	printf("map height = [%d]\n",data->map_width);
	data->player.move_dir = 0;
	data->player.turn_dir = 0;
	set_player(data, var);
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->map_width * TILE_SIZE,
		data->map_height * TILE_SIZE, "Cub3D");
	data->img.mlx_img = mlx_new_image(data->mlx,
		data->map_width * TILE_SIZE, data->map_height * TILE_SIZE);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img,
		&data->img.bpp, &data->img.line_len, &data->img.endian);
}

void	rendering(t_data *data, t_map_requirements *var)
{
	set_data(data, var);
	mlx_hook(data->win, 3, (1L<<1), key_release, data);
	mlx_hook(data->win, 2, (1L<<0), key_press, data);
	mlx_loop_hook(data->mlx, &game_render, data);
    mlx_loop(data->mlx);
}
