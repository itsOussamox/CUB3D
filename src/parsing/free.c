/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:09:49 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/08 14:02:50 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	free_2d(char **var)
{
	int	i;

	i = 0;
	while (var[i] != NULL)
	{
		free(var[i]);
		i++;
	}
	free(var);
}

void	free_file_path(t_map_requirements *var)
{
	free(var->ea);
	free(var->so);
	free(var->no);
	free(var->we);
	return ;
}
