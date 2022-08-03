/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:47:10 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/03 17:51:41 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	check_tab(t_map_requirements *var, char **tab, int index)
{
	if (ft_strlen(tab[0]) == 2 && tab[0][0] != '1' && tab[0][0] != '0')
	{
		if (ft_strncmp(tab[0], "NO", 2) != 0 && ft_strncmp(tab[0], "EA", 2) != 0
			&& ft_strncmp(tab[0], "WE", 2) != 0 && ft_strncmp(tab[0], "SO", 2) != 0)
				return(ft_putendl_fd("Error: wrong direction!", 2), free_2D(tab), 1);
		if (check_texture(var, tab) == 1)
			return(free_2D(tab), 1);
	}
	else if (ft_strlen(tab[0]) == 1 && tab[0][0] != '1' && tab[0][0] != '0')
	{
		if (tab[0][0] != 'C' && tab[0][0] != 'F')
			return (ft_putendl_fd("Error: no color", 2), free_2D(tab), 2);
		if (check_color(&var, tab[0][0], index) == 1)
			return(free(tab), 1);
	}
	else
		return(free_2D(tab), 3);
	return 0;
}

int	check_color(t_map_requirements **var, char landscape, int index)
{
	char	**tab;
	int		tabs_nb;

	tabs_nb = 0;
	tab = clear_tabs_and_spaces((*var)->map[index], " \t,");
	if (tab == NULL)
		return (perror("Error: malloc"), 1);
	while(tab[tabs_nb])
		tabs_nb++;
	if (tabs_nb != 4)
		return(ft_putendl_fd("Error: wrong rgb format!", 2), free_2D(tab), 1);
	if (check_color_args(tab) == 1 || check_color_args2(tab) == 1)
		return (1);
	if (landscape == 'C')
	{
		if ((*var)->C == -1)
			(*var)->C = 0 << 24 | ft_atoi(tab[1]) << 16 | ft_atoi(tab[2]) << 8 | ft_atoi(tab[3]);
		else
			return(free_2D(tab), ft_putendl_fd("Error: cant have more then one landscape", 2), 1);
	}
	else if (landscape == 'F')
	{
		if ((*var)->F == -1)
			(*var)->F = 0 << 24 | ft_atoi(tab[1]) << 16 | ft_atoi(tab[2]) << 8 | ft_atoi(tab[3]);
		else
			return(free_2D(tab), ft_putendl_fd("Error: cant have more then one landscape", 2), 1);
	}
	return (0);
}

int check_color_args(char **tab)
{
	int	i;
	int j;

	i = 1;
	while(i < 4)
	{
		j = 0;
		while(tab[i][j])
		{
			if (ft_isdigit(tab[i][j]) == 0)
				return (free_2D(tab), ft_putendl_fd("Error: wrong rgb format3", 2), 1);
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
	while(i < 4)
	{
		if (ft_atoi(tab[i]) < 0 || ft_atoi(tab[i]) > 255)
			return (free_2D(tab), ft_putendl_fd("Error: wrong rgb format", 2), 1);
		i++;
	}
	return (0);
}

int	check_texture(t_map_requirements *var, char **tab)
{
	if (ft_strncmp(".xpm", tab[1] + (ft_strlen(tab[1]) - 4) , 4) != 0
		|| tab[2] != NULL)
		return (ft_putendl_fd("Error: wrong argument!", 2), 1);
	if (fill_texture(var, tab) == 1)
		return (1);
	return 0;
}


int	fill_texture(t_map_requirements *var, char **tab)
{
	if (ft_strncmp(tab[0], "NO", 2 ) == 0)
	{
		if (var->NO != NULL)
			return (printf("Error: more then one NO orientation!\n"), 1);
		var->NO = ft_strdup(tab[1]);
	}
	else if (ft_strncmp(tab[0], "EA", 2 ) == 0)
	{
		if (var->EA != NULL)
			return (printf("Error: more then one EA orientation!\n"), 1);
		var->EA = ft_strdup(tab[1]);
	}
	else if (ft_strncmp(tab[0], "WE", 2 ) == 0)
	{
		if (var->WE != NULL)
			return (printf("Error: more then one WE orientation!\n"), 1);
		var->WE = ft_strdup(tab[1]);
	}
	else if (ft_strncmp(tab[0], "SO", 2 ) == 0)
	{
		if (var->SO != NULL)
			return (printf("Error: more then one SO orientation!\n"), 1);
		var->SO = ft_strdup(tab[1]);
	}
	return (0);
}
