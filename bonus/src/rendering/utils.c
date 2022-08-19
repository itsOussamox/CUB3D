/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:35:40 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/19 11:36:34 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"
#include "../../includes/parsing.h"

int	check_file(t_data *data)
{
	if (open(data->var->so, O_RDONLY) == -1)
	{
		free_2d(data->var->map);
		free_file_path(data->var);
		return (1);
	}
	else if (open(data->var->no, O_RDONLY) == -1)
	{
		free_2d(data->var->map);
		free_file_path(data->var);
		return (1);
	}
	if (check_file2(data) == 1)
		return (1);
	return (0);
}

int	check_file2(t_data *data)
{
	if (open(data->var->ea, O_RDONLY) == -1)
	{
		free_2d(data->var->map);
		free_file_path(data->var);
		return (1);
	}
	else if (open(data->var->we, O_RDONLY) == -1)
	{
		free_2d(data->var->map);
		free_file_path(data->var);
		return (1);
	}
	return (0);
}
