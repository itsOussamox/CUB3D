/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:41:41 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/04 17:58:28 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include "../utils/libft/libft.h"
#include "../utils/GetNextLine/get_next_line.h"

typedef struct	s_content
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
int		check_for_error(t_map_requirements **var);
int		check_tab(t_map_requirements *var, char **tab, int index);
int		check_color(t_map_requirements **var, char landscape, int index);
int 	check_color_args(char **tab);
int 	check_color_args2(char **tab);
int		check_texture(t_map_requirements *var, char **tab);
int		fill_texture(t_map_requirements *var, char **tab);

// utils

void	free_2D(char **var);
void	free_filePath(t_map_requirements *var);




//// new split
char	**clear_tabs_and_spaces(char *str, char *charset);
int	char_is_separator(char c, char *charset);
int	count_words(char *str, char *charset);
void	write_word(char *dest, char *from, char *charset);
void	write_split(char **split, char *str, char *charset);

#endif
