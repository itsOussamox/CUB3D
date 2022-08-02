/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:42 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/02 19:34:53 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	innit_map_rec(t_map_requirements *var)
{
	var->NO = NULL;
	var->SO = NULL;
	var->WE = NULL;
	var->EA = NULL;
	var->F = -1;
	var->C = -1;
	return;
}

char **fill_map(int file_dicriptor)
{
	char *line;
	char *all_lines;
	char **res;

	line = "";
	all_lines = ft_strdup("");
	while(line)
	{
		line = get_next_line(file_dicriptor);
		if (line == NULL)
			break;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	free(line);
	close(file_dicriptor);
	if (all_lines[0] == '\0')
	{
		ft_putendl_fd("Error: didnt read map!", 2);
		exit(EXIT_FAILURE);
	}
	res = ft_split(all_lines, '\n');
	free(all_lines);
	return (res);
}

void	check_directions(t_map_requirements **var)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while(i < 6)
	{
		if ((get_rgb(&var, i, &nb) == -1) || nb > 2)
		{
			printf("oy\n");
			ft_putendl_fd("Error: wrong game parameters!", 2);
			free_2D((*var)->map);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while(i < 6)
	{
		if (get_file_path(&var, i) == -1)
		{
			printf("yo\n");
			ft_putendl_fd("Error: wrong game parameters!", 2);
			free_2D((*var)->map);
			free_filePath(&var);
			exit(EXIT_FAILURE);
		}
		i++;
	}
		return;
}

void	check_map_requirements(t_map_requirements *var)
{
	check_directions(&var);
	return;
}
