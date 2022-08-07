/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:42 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/07 12:03:55 by aabdou           ###   ########.fr       */
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
	var->height = 0;
	var->Xplayer = 0;
	var->Yplayer = 0;
	var->player_orientaition = '\0';
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

int	check_NonMapElm_for_error(t_map_requirements **var)
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
			return (free_filePath((*var)), 1);
		i++;
	}
	if ((*var)->F == -1 || (*var)->C == -1 || (*var)->EA == NULL
		|| (*var)->NO == NULL || (*var)->SO == NULL || (*var)->WE == NULL)
			return(free_filePath((*var)), free_2D(tab),ft_putendl_fd("Error:\nmissing parameter", 2), 1);
	while((*var)->map[i++])
		(*var)->height++;
	return (0);
}

int	log_player_data(char c, t_map_requirements *var, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		var->Yplayer = i;
		var->Xplayer = j;
		var->player_orientaition = c;
		return (1);
	}
	return (0);
}

int	check_map_chars(char **map, t_map_requirements *var)
{
	int	nb_of_players;
	int	j;
	int	i;

	nb_of_players = 0;
	i = 6;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			nb_of_players += log_player_data(map[i][j], var, i, j);
			if (map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W' && map[i][j] != ' '
				&& map[i][j] != '\t' && map[i][j] != '1' && map[i][j] != '0')
				return(ft_putendl_fd("Error:\nunrecognized element in map!", 2), 1);
			j++;
		}
		i++;
	}
	if (nb_of_players != 1)
		return(ft_putendl_fd("Error:\nmore then one player!", 2), 1);
	return (0);
}

int	check_top_and_bottom_wall(t_map_requirements *var)
{
	int j;

	j = 0;
	while (var->map[6][j])
	{
		if (var->map[6][j] != '1' && var->map[6][j] != '\t' && var->map[6][j] != ' ')
			return (1);
		j++;
	}
	j = 0;
	while(var->map[var->height + 5][j])
	{
		if (var->map[var->height + 5][j] != '1' && var->map[var->height + 5][j]
			!= ' ' && var->map[var->height + 5][j] != '\t')
			return (1);
		j++;
	}
	return (0);
}

int	check_left_most_elem(char **map)
{
	int	i;
	int j;

	i = 6;
	while (map[i] && map[i][0])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] != '1')
			return (printf("wall err i = %d j = %d\n", i, j), 1);
		i++;
	}
	return (0);

}

int	check_right_most_elem(char **map)
{
	int	i;
	int j;

	i = 6;
	while (map[i] && map[i][ft_strlen(map[i]) - 1])
	{
		j = ft_strlen(map[i]) - 1;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j--;
		if (map[i][j] != '1')
			return (1);
		i++;
	}
	return (0);

}

int	check_first_and_last_elem(t_map_requirements *var)
{
	if (check_left_most_elem(var->map) == 1)
		return (1);
	if (check_right_most_elem(var->map) == 1)
		return (1);
	return (0);

}

size_t	ft_strlen2(const char *str)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '\t')
			count += 4;
		else
			count++;
		i++;
	}
	return (count);
}

int	check_if_valid_placement(char **map, int i, int j)
{
	if (map[i][j - 1] == ' ' || map[i][j - 1] == '\t'
	|| map[i][j + 1] == ' ' || map[i][j + 1] == '\t')
		return (1);
	else if (map[i + 1] != NULL)
	{
		if ((int)ft_strlen2(map[i - 1]) <= j || (int)ft_strlen2(map[i + 1]) <= j)
			return (1);
		else if (map[i - 1][j] == ' ' || map[i - 1][j] == '\t'
		|| map[i + 1][j] == ' ' || map[i + 1][j] == '\t')
		return (1);
	}
	return (0);
}



int	check_middle_lines(t_map_requirements *var)
{
	int	i;
	int	j;

	i = 6;
	while (var->map[i] != NULL)
	{
		j = 0;
		while (var->map[i][j] != '\0')
		{
			if (var->map[i + 1] != NULL)
			{
				if (var->map[i][j] != '1' && var->map[i][j] != ' '
					&& var->map[i][j] != '\t' && check_if_valid_placement(var->map, i, j))
						return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}


int	check_MapElm_for_error(t_map_requirements **var)
{
	if (check_map_chars((*var)->map, (*var)) == 1)
		return (1);
	if (check_top_and_bottom_wall((*var)) == 1 || check_first_and_last_elem((*var)) == 1)
		return(ft_putendl_fd("Error:\ninvalid wall!", 2), 1);
	if (check_middle_lines((*var)) == 1)
		return (ft_putendl_fd("Error:\ninvalid map!", 2), 1);
	return (0);
}

void	check_file_requirements(t_map_requirements *var)
{
	if (check_NonMapElm_for_error(&var) == 1)
		exit(EXIT_FAILURE);
	if (check_MapElm_for_error(&var) == 1)
		exit(EXIT_FAILURE);
	return;
}
