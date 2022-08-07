/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:29:18 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/07 17:36:17 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

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

int	check_if_valid_placement(char **map, int i, int j)
{
	if (map[i][j - 1] == ' ' || map[i][j - 1] == '\t'
	|| map[i][j + 1] == ' ' || map[i][j + 1] == '\t')
		return (1);
	if ((int)ft_strlen(map[i - 1]) <= j || (int)ft_strlen(map[i + 1]) <= j)
		return (1);
	else if (map[i - 1][j] == ' ' || map[i - 1][j] == '\t'
	|| map[i + 1][j] == ' ' || map[i + 1][j] == '\t')
		return (1);
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
