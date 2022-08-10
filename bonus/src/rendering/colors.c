/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:01:04 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/10 21:19:42 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

int	get_south_texture(t_data *data, int xoff, int yoff)
{
	return (data->so_data[(yoff * TILE_SIZE) + xoff]);
}