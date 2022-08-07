/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:27:02 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/07 12:28:40 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	check_color(t_map_requirements **var, char landscape, int index)
{
	char	**tab;
	int		tabs_nb;

	tabs_nb = 0;
	if (ft_isdigit((*var)->map[index][ft_strlen((*var)->map[index]) - 1]) == 0)
		return (ft_putendl_fd("Error:\nwrong rgb format", 2), 1);
	tab = clear_tabs_and_spaces((*var)->map[index], " \t,");
	if (tab == NULL)
		return (perror("Error:\nmalloc"), 1);
	while(tab[tabs_nb])
		tabs_nb++;
	if (tabs_nb != 4)
		return(ft_putendl_fd("Error:\nwrong rgb format!", 2), free_2D(tab), 1);
	if (check_color_args(tab) == 1 || check_color_args2(tab) == 1)
		return (1);
	if (landscape == 'C')
	{
		if ((*var)->C == -1)
			(*var)->C = ft_atoi(tab[1]) << 16 | ft_atoi(tab[2]) << 8 | ft_atoi(tab[3]);
		else
			return(free_2D(tab), ft_putendl_fd("Error:\ncant have more then one landscape", 2), 1);
	}
	else if (landscape == 'F')
	{
		if ((*var)->F == -1)
			(*var)->F = ft_atoi(tab[1]) << 16 | ft_atoi(tab[2]) << 8 | ft_atoi(tab[3]);
		else
			return(free_2D(tab), ft_putendl_fd("Error:\ncant have more then one landscape", 2), 1);
	}
	return (free_2D(tab), 0);
}

int check_color_args(char **tab)
{
	int	i;
	int j;

	i = 1;
	while(tab[i])
	{
		j = 0;
		while(tab[i][j] != '\0')
		{
			if (tab[i][j] != '\0' && ft_isdigit(tab[i][j]) == 0)
				return (free_2D(tab), ft_putendl_fd("Error:\nwrong rgb format", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int check_color_args2(char **tab)
{
	int	i;

	i = 1;
	while(tab[i])
	{
		if (ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			return (free_2D(tab), ft_putendl_fd("Error:\nwrong rgb format", 2), 1);
		i++;
	}
	return (0);
}
