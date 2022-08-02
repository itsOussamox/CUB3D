/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:41:41 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/02 14:44:53 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include "../utils/libft/libft.h"
#include "../utils/GetNextLine/get_next_line.h"

typedef struct	content
{
	char* NO;
	char* SO;
	char* WE;
	char* EA;
	int F;
	int C;
	char **map;
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
void	free_filePath(t_map_requirements ***var);
int		get_file_path(t_map_requirements ***var, int flag);
int		get_rgb(t_map_requirements ***var, int flag, int *nb);



//// new split
char	**clear_tabs_and_spaces(char *str, char *charset);
int	char_is_separator(char c, char *charset);
int	count_words(char *str, char *charset);
void	write_word(char *dest, char *from, char *charset);
void	write_split(char **split, char *str, char *charset);

#endif
