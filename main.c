/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:43:30 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/07 17:02:08 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/parsing.h"

size_t	ft_strlen2(const char *str)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
			count += 4;
		else
			count++;
		i++;
	}
	return (count);
}

void	innit_map_rec(t_map_requirements *var)
{
	var->NO = NULL;
	var->SO = NULL;
	var->WE = NULL;
	var->EA = NULL;
	var->F = -1;
	var->C = -1;
	var->height = 0;
	var->Xplayer = 0;
	var->Yplayer = 0;
	var->player_orientaition = '\0';
	return;
}

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
		if (check_file_requirements(&var))
			return (free_2D(var.map), free_filePath(&var), 1);
		printf("[%s]\n[%s]\n[%s]\n[%s]\n", var.WE, var.EA, var.NO, var.SO);
		printf("%d, %d \n", var.C, var.F);
		printf("height: %d\n", var.height);
		printf("player y = %d\nplayer x = %d\nplayer direction = %c\n", var.Yplayer, var.Xplayer, var.player_orientaition);
		free_filePath(&var);
		free_2D(var.map);
	}


	return 0;
}

