/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:53:16 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/21 19:53:18 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	loop_through_string(char *str)
{
	int	i;
	int	comma_count;

	comma_count = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count != 2)
		return (1);
	return (0);
}

void	check_comma(t_map_requirements *var, char *str)
{
	char	*tab;

	tab = ft_substr(str, 0, 1);
	if (ft_strncmp(tab, "C", 1) == 0 || ft_strncmp(tab, "F", 1) == 0)
	{
			if (loop_through_string(str) == 1)
			{
				printf("Error:\nwrong RGB format!\n");
				free_2d(var->map);
				free(tab);
				free_file_path(var);
				exit(EXIT_FAILURE);
			}
	}
	free(tab);
	return ;
}
