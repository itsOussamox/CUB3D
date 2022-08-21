/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:41:41 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/21 19:49:30 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../utils/libft/libft.h"
# include "../utils/GetNextLine/get_next_line.h"

typedef struct s_content
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f;
	int			c;
	int			height;
	int			width;
	char		**map;
	int			x_player;
	int			y_player;
	char		player_orientaition;
}				t_map_requirements;

// argument parsing
void	open_file(int *fd, char *file_name);
void	check_file_type(char *path, char *ext);
void	check_argument(int ac, char **av, int *fd);

// checking map requirements
void	innit_map_rec(t_map_requirements *var);
char	**fill_map(int file_dicriptor);
int		check_file_requirements(t_map_requirements *var);
int		check_non_map_elm_for_error(t_map_requirements **var);
int		check_tab(t_map_requirements *var, char **tab, int index);
int		check_color(t_map_requirements **var, char landscape, int index);
int		check_color_args(char **tab);
int		check_color_args2(char **tab);
int		check_texture(t_map_requirements *var, char **tab);
int		fill_texture(t_map_requirements *var, char **tab);
int		check_middle_lines(t_map_requirements *var);
int		check_if_valid_placement(char **map, int i, int j);
int		check_right_most_elem(char **map);
int		check_left_most_elem(char **map);
int		check_top_and_bottom_wall(t_map_requirements *var);
int		check_map_elm_for_error(t_map_requirements **var);
int		check_first_and_last_elem(t_map_requirements *var);
int		check_map_chars(char **map, t_map_requirements *var);
int		log_player_data(char c, t_map_requirements *var, int i, int j);
int		check_non_map_elm_for_error(t_map_requirements **var);
int		init_collers(t_map_requirements *var, char landscape, char **tab);

// utils
void	free_2d(char **var);
char	**clear_tabs_and_spaces(char *str, char *charset);
void	get_map_height_and_width(int i, t_map_requirements *var);
void	free_file_path(t_map_requirements *var);
int		loop_through_string(char *str);
void	check_comma(t_map_requirements *var, char *str);

#endif
