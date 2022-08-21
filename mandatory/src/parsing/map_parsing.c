/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:37:42 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/21 19:56:30 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	check_non_map_elm_for_error(t_map_requirements **var)
{
	int		i;
	char	**tab;
	int		return_value;

	i = -1;
	while ((*var)->map[++i])
	{
		check_comma((*var), (*var)->map[i]);
		tab = clear_tabs_and_spaces((*var)->map[i], " \t");
		return_value = check_tab((*var), tab, i);
		if (return_value == 2)
			continue ;
		else if (return_value == 3)
			break ;
		else if (return_value == 1)
			return (free_file_path((*var)), 1);
	}
	if ((*var)->f == -1 || (*var)->c == -1 || (*var)->ea == NULL
		|| (*var)->no == NULL || (*var)->so == NULL || (*var)->we == NULL)
	{
		ft_putendl_fd("Error:\nmissing parameter", 2);
		return (free_file_path((*var)), 1);
	}
	get_map_height_and_width(i, (*var));
	return (0);
}

int	log_player_data(char c, t_map_requirements *var, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		var->y_player = i;
		var->x_player = j;
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
	i = 5;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			nb_of_players += log_player_data(map[i][j], var, i, j);
			if (map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W' && map[i][j] != ' '
				&& map[i][j] != '1' && map[i][j] != '0')
			{
				ft_putendl_fd("Error:\nunrecognized element in map!", 2);
				return (1);
			}
		}
	}
	if (nb_of_players != 1)
		return (ft_putendl_fd("Error:\ninvalid number of players!", 2), 1);
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

int	check_map_elm_for_error(t_map_requirements **var)
{
	if (check_map_chars((*var)->map, (*var)) == 1)
		return (1);
	if (check_top_and_bottom_wall((*var)) == 1
		|| check_first_and_last_elem((*var)) == 1)
		return (ft_putendl_fd("Error:\ninvalid wall!", 2), 1);
	if (check_middle_lines((*var)) == 1)
		return (ft_putendl_fd("Error:\ninvalid map!", 2), 1);
	return (0);
}
