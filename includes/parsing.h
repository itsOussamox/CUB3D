/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:41:41 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/07 12:48:18 by aabdou           ###   ########.fr       */
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
	int height;
	char **map;
	int Xplayer;
	int Yplayer;
	char player_orientaition;
}				t_map_requirements;

// argument parsing

void	open_file(int *fd, char *file_name);
void	check_file_type(char *path, char *ext);
void	check_argument(int ac, char **av, int *fd);


// checking map requirements

void	innit_map_rec(t_map_requirements *var);
char	**fill_map(int file_dicriptor);
void	check_file_requirements(t_map_requirements *var);
int		check_NonMapElm_for_error(t_map_requirements **var);
int		check_tab(t_map_requirements *var, char **tab, int index);
int		check_color(t_map_requirements **var, char landscape, int index);
int 	check_color_args(char **tab);
int 	check_color_args2(char **tab);
int		check_texture(t_map_requirements *var, char **tab);
int		fill_texture(t_map_requirements *var, char **tab);
int		check_middle_lines(t_map_requirements *var);
int		check_if_valid_placement(char **map, int i, int j);
int		check_right_most_elem(char **map);
int		check_left_most_elem(char **map);
int		check_top_and_bottom_wall(t_map_requirements *var);
int		check_MapElm_for_error(t_map_requirements **var);
int		check_first_and_last_elem(t_map_requirements *var);
int		check_map_chars(char **map, t_map_requirements *var);
int		log_player_data(char c, t_map_requirements *var, int i, int j);
int		check_NonMapElm_for_error(t_map_requirements **var);

// utils

void	free_2D(char **var);
void	free_filePath(t_map_requirements *var);
size_t	ft_strlen2(const char *str);



//// new split
char	**clear_tabs_and_spaces(char *str, char *charset);
int	char_is_separator(char c, char *charset);
int	count_words(char *str, char *charset);
void	write_word(char *dest, char *from, char *charset);
void	write_split(char **split, char *str, char *charset);

#endif
