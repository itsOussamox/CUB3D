/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:54 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/09 23:49:46 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"
/* 
	TO DO LIST :
	- MINIMAP ADJUSTEMENT [70%]
	- MOVE PLAYER LEFT AND RIGHT [0%]
	- TEXTURE MAPPING [0%]
	- DOORS [0%]
 */

void	get_mouse_data(t_data *data)
{
	int x;
	int y;

	if (!MOUSE_MOVE)
		return ;
	mlx_mouse_get_pos(data->win, &x, &y);
	if (x > data->mouse.mid_x)
		data->player.turn_dir = 1;
	if (x < data->mouse.mid_x)
		data->player.turn_dir = -1;
	if (x == data->mouse.mid_x)
		data->player.turn_dir = 0;
	mlx_mouse_move(data->win, data->window_width / 2 , data->window_height / 2);
}

int	end_game(t_data *data)
{
	if (data->rays)
		free(data->rays);
	free_file_path(data->var);
	free_2d(data->var->map);
	exit(0);
	return (1);
}

int	game_render(t_data *data)
{
	get_mouse_data(data);
	render_angle(data);
	player_move(data);
	cast_rays(data);
	render_3d(data);
	render_2d(data);
	free(data->rays);
	data->rays = NULL;
	return (1);
}

static void set_data(t_data *data, t_map_requirements *var)
{
	data->rays = NULL;
	data->scale = SCALE;
	data->var = var;
	data->alpha = 1;
	data->map_height = var->height;
	data->map_width = var->width;
	data->window_width = 1920;
	data->window_height = 1080;
	data->mouse.mid_x = data->window_width / 2;
	data->mouse.mid_y = data->window_height / 2;
	data->minisize = TILE_SIZE;
	data->map = var->map + 6;
	data->player.move_dir = 0;
	data->player.turn_dir = 0;
	data->c_color = var->c;
	data->f_color = var->f;
	set_player(data, var);
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->window_width,
		data->window_height, "Cub3D");
	data->img.mlx_img = mlx_new_image(data->mlx,
		data->window_width, data->window_height);
	data->img.addr = (int *)mlx_get_data_addr(data->img.mlx_img,
		&data->img.bpp, &data->img.line_len, &data->img.endian);
	data->img.line_len /= 4;
}

void	rendering(t_data *data, t_map_requirements *var)
{
	set_data(data, var);
	mlx_mouse_hide();
	mlx_hook(data->win, 17, 0, end_game, data);
	mlx_hook(data->win, 3, (1L<<1), key_release, data);
	mlx_hook(data->win, 2, (1L<<0), key_press, data);
	mlx_loop_hook(data->mlx, &game_render, data);
    mlx_loop(data->mlx);
}
