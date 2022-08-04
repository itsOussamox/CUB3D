/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:42 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/04 18:19:24 by aabdou           ###   ########.fr       */
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
	if (all_lines[0] == '\0')
	{
		ft_putendl_fd("Error:\ndidnt read map!", 2);
		exit(EXIT_FAILURE);
	}
	res = ft_split(all_lines, '\n');
	free(all_lines);
	return (res);
}

int	check_for_error(t_map_requirements **var)
{
	int i;
	char **tab;
	int return_value;

	i = 0;
	while((*var)->map[i])
	{
		tab = clear_tabs_and_spaces((*var)->map[i], " \t");
		return_value = check_tab((*var), tab, i);
		if (return_value == 2)
			continue;
		else if (return_value == 3)
			break;
		else if (return_value == 1)
			return (free_filePath((*var)), free_2D(tab), 1);
		i++;
	}
	if ((*var)->F == -1 || (*var)->C == -1 || (*var)->EA == NULL
		|| (*var)->NO == NULL || (*var)->SO == NULL || (*var)->WE == NULL)
			return(free_filePath((*var)), free_2D(tab) , ft_putendl_fd("Error:\nmissing parameter", 2), 1);
	return (free_2D(tab), 0);
}

void	check_map_requirements(t_map_requirements *var)
{
	check_for_error(&var);
	return;
}
