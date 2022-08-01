/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:43:30 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/01 19:20:04 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/parsing.h"

int main(int ac, char **av)
{
	int file_distiptor;
	t_map_requirements var;

	check_argument(ac, av, &file_distiptor);
	innit_map_rec(&var);
	var.map = fill_map(file_distiptor);
	if (var.map != NULL)
	{
		check_map_requirements(&var);
	}


	return 0;
}

