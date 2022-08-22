/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:46:10 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/22 14:12:04 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"
#include "../../includes/parsing.h"

void	ft_free(t_data *data, char *str)
{
	free_2d(data->var->map);
	free_file_path(data->var);
	printf("Error:\n%s\n", str);
	exit(EXIT_FAILURE);
}

void	set_textures2(t_data *data)
{
	int	tab[2];

	data->ea_img = mlx_xpm_file_to_image(data->mlx,
			data->var->ea, &tab[0], &tab[1]);
	if (data->ea_img == NULL)
		ft_free(data, "EA wall texture");
	data->ea_data = (int *)mlx_get_data_addr(data->ea_img,
			&tab[0], &tab[0], &tab[0]);
	data->no_img = mlx_xpm_file_to_image(data->mlx,
			data->var->no, &tab[0], &tab[1]);
	if (data->no_img == NULL)
		ft_free(data, "NO wall texture");
	data->no_data = (int *)mlx_get_data_addr(data->no_img,
			&tab[0], &tab[0], &tab[0]);
	return ;
}
