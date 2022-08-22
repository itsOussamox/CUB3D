/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:24:54 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/22 13:58:25 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	set_textures(t_data *data)
{
	int	tab[2];

	if (check_file(data) == 1)
		ft_free(data, "texture files missing!");
	data->mlx = mlx_init();
	data->so_img = mlx_xpm_file_to_image(data->mlx,
			data->var->so, &tab[0], &tab[1]);
	if (data->so_img == NULL)
		ft_free(data, "SO wall texture");
	data->so_data = (int *)mlx_get_data_addr(data->so_img,
			&tab[0], &tab[0], &tab[0]);
	data->we_img = mlx_xpm_file_to_image(data->mlx,
			data->var->we, &tab[0], &tab[1]);
	if (data->we_img == NULL)
		ft_free(data, "WE wall texture");
	data->we_data = (int *)mlx_get_data_addr(data->we_img,
			&tab[0], &tab[0], &tab[0]);
	data->ea_img = mlx_xpm_file_to_image(data->mlx,
			data->var->ea, &tab[0], &tab[1]);
	set_textures2(data);
	return ;
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
	render_3d(data, -1);
	render_2d(data);
	free(data->rays);
	data->rays = 0;
	return (1);
}

static void	set_data(t_data *data, t_map_requirements *var)
{
	data->var = var;
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
	data->fov_angel = FOV * (M_PI / 180);
	data->minisize = TILE_SIZE;
	data->player_size = TILE_SIZE / 8;
	data->rotation_s = 2 * (M_PI / 180);
	data->map = var->map + 6;
	data->c_color = var->c;
	data->f_color = var->f;
	set_data2(data, var);
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
