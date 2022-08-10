/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:47:10 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/08 14:05:37 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

char	**fill_map(int file_dicriptor)
{
	char	*line;
	char	*all_lines;
	char	**res;

	line = "";
	all_lines = ft_strdup("");
	while (line)
	{
		line = get_next_line(file_dicriptor);
		if (line == NULL)
			break ;
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

int	check_tab(t_map_requirements *var, char **tab, int index)
{
	if (ft_strlen(tab[0]) == 2 && tab[0][0] != '1' && tab[0][0] != '0')
	{
		if (ft_strncmp(tab[0], "NO", 2) != 0 && ft_strncmp(tab[0], "EA", 2) != 0
			&& ft_strncmp(tab[0], "WE", 2) != 0
			&& ft_strncmp(tab[0], "SO", 2) != 0)
		{
			ft_putendl_fd("Error:\nwrong direction!", 2);
			return (free_2d(tab), 1);
		}
		if (check_texture(var, tab) == 1)
			return (free_2d(tab), 1);
	}
	else if (ft_strlen(tab[0]) == 1 && tab[0][0] != '1' && tab[0][0] != '0')
	{
		if (tab[0][0] != 'C' && tab[0][0] != 'F')
			return (ft_putendl_fd("Error:\nno color", 2), free_2d(tab), 2);
		if (check_color(&var, tab[0][0], index) == 1)
			return (free(tab), 1);
	}
	else
		return (free_2d(tab), 3);
	return (free_2d(tab), 0);
}

int	check_texture(t_map_requirements *var, char **tab)
{
	if (ft_strncmp(".xpm", tab[1] + (ft_strlen(tab[1]) - 4), 4) != 0
		|| tab[2] != NULL)
		return (ft_putendl_fd("Error:\nwrong argument!", 2), 1);
	if (fill_texture(var, tab) == 1)
		return (1);
	return (0);
}

int	fill_texture(t_map_requirements *var, char **tab)
{
	if (ft_strncmp(tab[0], "NO", 2) == 0)
	{
		if (var->no != NULL)
			return (printf("Error:\nmore then one NO orientation!\n"), 1);
		var->no = ft_strdup(tab[1]);
	}
	else if (ft_strncmp(tab[0], "EA", 2) == 0)
	{
		if (var->ea != NULL)
			return (printf("Error:\nmore then one EA orientation!\n"), 1);
		var->ea = ft_strdup(tab[1]);
	}
	else if (ft_strncmp(tab[0], "WE", 2) == 0)
	{
		if (var->we != NULL)
			return (printf("Error:\nmore then one WE orientation!\n"), 1);
		var->we = ft_strdup(tab[1]);
	}
	else if (ft_strncmp(tab[0], "SO", 2) == 0)
	{
		if (var->so != NULL)
			return (printf("Error:\nmore then one SO orientation!\n"), 1);
		var->so = ft_strdup(tab[1]);
	}
	return (0);
}

int	check_file_requirements(t_map_requirements *var)
{
	if (var->map[6] == NULL)
		return (ft_putendl_fd("Error:\nno map!", 2), 1);
	if (check_non_map_elm_for_error(&var) == 1)
		exit(EXIT_FAILURE);
	if (check_map_elm_for_error(&var) == 1)
		exit(EXIT_FAILURE);
	return (0);
}
