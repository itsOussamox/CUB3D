/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:41:41 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/01 19:19:51 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include "../utils/libft/libft.h"
#include "../utils/GetNextLine/get_next_line.h"

typedef struct rgb
{
	int C[3];
	int F[3];
}				t_colors;


typedef struct values
{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
}				t_values;


typedef struct	content
{
	int NO;
	int SO;
	int WE;
	int EA;
	int F;
	int C;
	char **map;
	t_colors	rgb;
	t_values	file_path;
}				t_map_requirements;




// argument parsing

void	open_file(int *fd, char *file_name);
void	check_file_type(char *path, char *ext);
void	check_argument(int ac, char **av, int *fd);


// checking map requirements

void	innit_map_rec(t_map_requirements *var);
char	**fill_map(int file_dicriptor);
void	check_map_requirements(t_map_requirements *var);
void	check_directions(t_map_requirements **var);

// utils

void	free_2D(char **var);
void	remove_space_and_tabs(char *str, char **path, char **name);


#endif
