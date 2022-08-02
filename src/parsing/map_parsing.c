/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:42 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/02 11:54:38 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	innit_map_rec(t_map_requirements *var)
{
	var->NO = 0;
	var->SO = 0;
	var->WE = 0;
	var->EA = 0;
	var->F = 0;
	var->C = 0;
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
	int i = 0;
	while(i < 6)
	{
		if (remove_space_and_tabs(&var, i) == -1)
		{
			ft_putendl_fd("Error: wrong map parameters!", 2);
			free((*var)->map);
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
