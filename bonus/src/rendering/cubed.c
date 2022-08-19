/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:54 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/19 11:42:22 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"
/*
	TO DO LIST :
	- MOVE PLAYER LEFT AND RIGHT [30%]
	- DOORS [80%]
	TO UNDERSTAND LIST :
	- hypot
	- ray distance
*/

void	*set_textures(t_data *data)
{
	int	tab[2];

	if (check_file(data) == 1)
		return (printf("Error:\ntexture file!\n"), exit(EXIT_FAILURE), NULL);
	data->so_img = mlx_xpm_file_to_image(data->mlx,
			data->var->so, &tab[0], &tab[1]);
	data->so_data = (int *)mlx_get_data_addr(data->so_img,
			&tab[0], &tab[0], &tab[0]);
	data->we_img = mlx_xpm_file_to_image(data->mlx,
			data->var->we, &tab[0], &tab[1]);
	data->we_data = (int *)mlx_get_data_addr(data->we_img,
			&tab[0], &tab[0], &tab[0]);
	data->ea_img = mlx_xpm_file_to_image(data->mlx,
			data->var->ea, &tab[0], &tab[1]);
	data->ea_data = (int *)mlx_get_data_addr(data->ea_img,
			&tab[0], &tab[0], &tab[0]);
	data->no_img = mlx_xpm_file_to_image(data->mlx,
			data->var->no, &tab[0], &tab[1]);
	data->no_data = (int *)mlx_get_data_addr(data->no_img,
			&tab[0], &tab[0], &tab[0]);
	data->door_img = mlx_xpm_file_to_image(data->mlx,
			DOOR_TEXT, &tab[0], &tab[1]);
	data->door_data = (int *)mlx_get_data_addr(data->door_img,
			&tab[0], &tab[0], &tab[0]);
	return (NULL);
}

int	end_game(t_data *data)
{
	if (data->rays)
		free(data->rays);
	free_file_path(data->var);
	free_2d(data->var->map);
	mlx_destroy_image(data->mlx, data->door_img);
	mlx_destroy_image(data->mlx, data->so_img);
	mlx_destroy_image(data->mlx, data->no_img);
	mlx_destroy_image(data->mlx, data->we_img);
	mlx_destroy_image(data->mlx, data->ea_img);
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	exit(0);
	return (1);
}

int	game_render(t_data *data)
{
	if (MOUSE_MOVE)
		get_mouse_data(data);
	render_angle(data);
	player_move(data);
	player_strafe(data);
	cast_rays(data);
	open_door(data);
	render_3d(data);
	render_2d(data);
	free(data->rays);
	data->rays = 0;
	return (1);
}

static void	set_data(t_data *data, t_map_requirements *var)
{
	data->var = var;
	data->mlx = mlx_init();
	set_textures(data);
	data->rays = 0;
	data->scale = SCALE;
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
	data->player.strafe_dir = 0;
	data->c_color = var->c;
	data->f_color = var->f;
	set_player(data, var);
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
	if (MOUSE_MOVE)
		mlx_mouse_hide();
	mlx_hook(data->win, 17, 0, end_game, data);
	mlx_hook(data->win, 3, (1L << 1), key_release, data);
	mlx_hook(data->win, 2, (1L << 0), key_press, data);
	mlx_loop_hook(data->mlx, &game_render, data);
	mlx_loop(data->mlx);
}
