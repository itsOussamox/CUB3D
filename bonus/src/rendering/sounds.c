/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:47:28 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/13 12:42:58 by aabdou           ###   ########.fr       */
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
