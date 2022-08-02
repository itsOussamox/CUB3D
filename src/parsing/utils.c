/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:47:10 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/02 18:02:14 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	get_file_path(t_map_requirements ***var , int flag)
{
	char	**tab;

	tab = clear_tabs_and_spaces((*(*var))->map[flag], " \t");
	if (tab == NULL)
		return -1;
	if (ft_strncmp(tab[0], "NO", 3) == 0 && tab[1] != NULL && (*(*var))->NO == NULL)
		return ((*(*var))->NO = ft_strdup(tab[1]), free_2D(tab), 0);
	else if (ft_strncmp(tab[0], "SO", 3) == 0 && tab[1] != NULL && (*(*var))->SO == NULL)
		return ((*(*var))->SO = ft_strdup(tab[1]), free_2D(tab), 0);
	else if (ft_strncmp(tab[0], "WE", 3) == 0 && tab[1] != NULL && (*(*var))->WE == NULL)
		return ((*(*var))->WE = ft_strdup(tab[1]), free_2D(tab), 0);
	else if (ft_strncmp(tab[0], "EA", 3) == 0 && tab[1] != NULL && (*(*var))->EA == NULL)
		return ((*(*var))->EA = ft_strdup(tab[1]), free_2D(tab), 0);

	return (free_2D(tab), -1);
}

int get_rgb(t_map_requirements ***var, int flag, int *nb)
{
	char **tab;

	tab = clear_tabs_and_spaces((*(*var))->map[flag], " \t,");
	if (tab == NULL)
		return -1;
	if (ft_strncmp(tab[0], "C", 2) == 0 && tab[1] && tab[2] && tab[3])
	{
		nb++;
		(*(*var))->C = 0 << 24 | ft_atoi(tab[1]) << 16 | ft_atoi(tab[2]) << 8 | ft_atoi(tab[3]);
		free_2D(tab);
		return (0);
	}
	else if (ft_strncmp(tab[0], "F", 2) == 0 && tab[1] && tab[2] && tab[3])
	{
		nb++;
		(*(*var))->F = 0 << 24 | ft_atoi(tab[1]) << 16 | ft_atoi(tab[2]) << 8 | ft_atoi(tab[3]);
		free_2D(tab);
		return (0);
	}
	if ((*(*var))->C != -1 || (*(*var))->F != -1 )
		return 0;
	return (-1);
}
