/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:42 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/07 13:32:35 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"


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


int	check_first_and_last_elem(t_map_requirements *var)
{
	if (check_left_most_elem(var->map) == 1)
		return (1);
	if (check_right_most_elem(var->map) == 1)
		return (1);
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

