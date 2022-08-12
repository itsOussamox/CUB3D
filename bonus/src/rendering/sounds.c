/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:47:28 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/12 16:41:59 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	ft_playsound(int sound)
{
	int	i;
	
	i = fork();
	if (i == 0)
	{
		if (sound == 2)
			system("/usr/bin/afplay sounds/door_open.wav");
		exit(0);
	}
}