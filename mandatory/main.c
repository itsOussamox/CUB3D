/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:43:30 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/24 16:22:41 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/parsing.h"
#include "./includes/cubed.h"

void	get_map_height_and_width(int i, t_map_requirements *var)
{
	int	width;
	int	max_width;

	max_width = 0;
	width = 0;
	while (var->map[i])
	{
		width = (int)ft_strlen(var->map[i]);
		if (max_width < width)
			max_width = width;
		var->height++;
		i++;
	}
	var->width = max_width;
	return ;
}

void	innit_map_rec(t_map_requirements *var)
{
	var->no = NULL;
	var->so = NULL;
	var->we = NULL;
	var->ea = NULL;
	var->f = -1;
	var->c = -1;
	var->height = 0;
	var->x_player = 0;
	var->y_player = 0;
	var->player_orientaition = '\0';
	return ;
}

int	main(int ac, char **av)
{
	int					file_distiptor;
	t_map_requirements	var;
	t_data				data;

	check_argument(ac, av, &file_distiptor);
	innit_map_rec(&var);
	var.map = fill_map(file_distiptor);
	if (close(file_distiptor) == -1)
		return (free_2d(var.map), ft_putendl_fd("Error:\ncant close fd", 2), 1);
	if (var.map != NULL)
	{
		if (check_file_requirements(&var))
			return (free_2d(var.map), free_file_path(&var), 1);
	}
	rendering(&data, &var);
	return (0);
}
