/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:09:49 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/02 13:51:01 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	free_2D(char **var)
{
	int	i;

	i = 0;
	while(var[i] != NULL)
	{
		free(var[i]);
		i++;
	}
	free(var);
}

void	free_filePath(t_map_requirements ***var)
{
	free((*(*var))->EA);
	free((*(*var))->SO);
	free((*(*var))->NO);
	free((*(*var))->WE);
}
