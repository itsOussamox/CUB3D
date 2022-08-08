/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:43:30 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/08 22:43:24 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/parsing.h"
#include "./includes/cubed.h"

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
    t_data	data;

	check_argument(ac, av, &file_distiptor);
	innit_map_rec(&var);
	var.map = fill_map(file_distiptor);
	if (close(file_distiptor) == -1)
		return (free_2d(var.map), ft_putendl_fd("Error:\ncant close fd", 2), 1);
	if (var.map != NULL)
	{
		if (check_file_requirements(&var))
			return (free_2d(var.map), free_file_path(&var), 1);
		printf("[%s]\n[%s]\n[%s]\n[%s]\n", var.we, var.ea, var.no, var.so);
		printf("%d, %d \n", var.c, var.f);
		printf("height: %d\n", var.height);
		printf("player y = %d\nplayer x = %d\nplayer direction = %c\n", var.y_player, var.x_player, var.player_orientaition);
	}
	rendering(&data, &var);
	return (0);
}
