/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:43:30 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/06 18:21:53 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/parsing.h"

int main(int ac, char **av)
{
	int file_distiptor;
	t_map_requirements var;

	check_argument(ac, av, &file_distiptor);
	innit_map_rec(&var);
	var.map = fill_map(file_distiptor);
	if(close(file_distiptor) == -1)
		return (free_2D(var.map), ft_putendl_fd("Error:\ncant close fd", 2), 1);
	if (var.map != NULL)
	{
		check_file_requirements(&var);
		printf("[%s]\n[%s]\n[%s]\n[%s]\n", var.WE, var.EA, var.NO, var.SO);
		printf("%d, %d \n", var.C, var.F);
		printf("height: %d\n", var.height);
		printf("player y = %d\nplayer x = %d\nplayer direction = %c\n", var.Yplayer, var.Xplayer, var.player_orientaition);
		free_filePath(&var);
		free_2D(var.map);
	}


	return 0;
}

