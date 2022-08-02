/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:47:10 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/02 13:14:44 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	remove_space_and_tabs(t_map_requirements ***var , int flag)
{
	char	**tab;


	tab = clear_tabs_and_spaces((*(*var))->map[flag], " \t,");
	if (tab == NULL)
		return -1;
	while(tab[i])
		printf("%s\n", tab[i++]);
	if (ft_strncmp(tab[0], "NO", 3) == 0 && tab[1] != NULL)
		return ((*(*var))->NO = ft_strdup(tab[1]), free_2D(tab), 0);
	else if (ft_strncmp(tab[0], "SO", 3) == 0 && tab[1] != NULL)
		return ((*(*var))->SO = ft_strdup(tab[1]), free_2D(tab), 0);
	else if (ft_strncmp(tab[0], "WE", 3) == 0 && tab[1] != NULL)
		return ((*(*var))->WE = ft_strdup(tab[1]), free_2D(tab), 0);
	else if (ft_strncmp(tab[0], "EA", 3) == 0 && tab[1] != NULL)
		return ((*(*var))->EA = ft_strdup(tab[1]), free_2D(tab), 0);
	return (free_2D(tab), -1);
}
