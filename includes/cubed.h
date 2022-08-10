/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouadel <obouadel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:26:16 by obouadel          #+#    #+#             */
/*   Updated: 2022/08/10 14:27:48 by obouadel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
#define CUBED_H
#include "../mlx/mlx.h"
#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <limits.h>

/* COLORS */
#define GROUND_COLOR 0x808080
#define WALL_COLOR 0x212121
/* WINDOW SETTINGS */
#define FOV 60
#define FOV_ANGLE FOV * (M_PI / 180)
#define WSTRIP 1
#define SCALE 0.25
#define TILE_SIZE 32
#define GRID 0
//PLAYER SETTINGS
#define PLAYER_SIZE TILE_SIZE / 8
#define PLAYER_COLOR 0x0000FF
#define PLAYER_SPEED 5
#define ROTATION_SPEED 2 * (M_PI / 180)
#define PLAYER_RAY 10
#define	MOUSE_MOVE 0
//KEYHOOKS
#define W 13
#define S 1
#define A 0
#define D 2
#define ESCAPE 53
#define RIGHT 124
#define LEFT 123
#define	M 46

// Mouse data
typedef struct s_mouse
{
	int	mid_x;
	int	mid_y;
	int	x;
	int	y;
}	t_mouse;

// Rect data
typedef struct s_rect
{
	int	x;
	int	y;
	int	dx;
	int	dy;
}	t_rect;

// Rays data
typedef struct s_ray
{
	double	horzwallhitx;
	double	horzwallhity;
	double	vertwallhitx;
	double	vertwallhity;
	char	hitpointv;
	char	hitpointh;
	double	wallhitx;
	double	wallhity;
	double	xstep;
	double	ystep;
	double	ra;
}	t_ray;

typedef struct s_rays
{
	double	distance;
	double	wallhitx;
	double	wallhity;
	char	sym;
	char	tab_hit;
	double	angle;
}	t_rays;
// Image to draw on
typedef struct s_img
{
	void	*mlx_img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

// Player's informations
typedef struct s_player
{
	double		x;
	double		y;
	int		move_dir;
	int		turn_dir;
	int		strafe_dir;
	double	pa;
}	t_player;

// mlx and map's data
typedef struct s_data
{
	t_map_requirements	*var;
	t_player			player;
	t_img				img;
	t_ray				ray;
	t_rays				*rays;
	t_mouse				mouse;
	double				scale;
	int					minisize;
	int					numofrays;
	int					alpha;
    void				*mlx;
    void				*win;
	int					window_height;
	int					window_width;
	int 				map_height;
	int 				map_width;
	int					f_color;
	int					c_color;
	char 				**map;
}   t_data;

/* Drawing */
void 	draw_rect(t_data *data, int rectx, int recty, int color);
void	draw_player(t_data *data);
void	ft_background_fill(t_data *data, int size, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_data *data, double beginX, double beginY, double endX, double endY);
t_rect	get_rect(int x, int y, int dx, int dy);
void	draw_wall(t_data *data, t_rect rect, int color);
void	draw_top(t_data *data, t_rect a);
void	draw_bot(t_data *data, t_rect a);

/* Rendring */
void	render_2d(t_data *data);
void	render_3d(t_data *data);
void	draw_map(t_data *data);
void	render_angle(t_data *data);
void	render_rays(t_data *data);
void	rendering(t_data *data, t_map_requirements *var);

/* Utils */
int		get_floor(double x, t_data data);
int		is_player(char c);
int		end_game(t_data *data);
int		get_wall_color(t_data *data, int i);


/* Ray Casting */
int		game_render(t_data *data);
void	draw_ray(t_data *data);
void	cast_rays(t_data *data);
void	ray_cast(t_data *data, double rayAngle, int i);
int		ray_facingright(double angle);
int		ray_facingleft(double angle);
int		ray_facingdown(double angle);
int		ray_facingup(double angle);
int		ray_out_of_map(t_data *data, double x, double y);
double	adjust_ray_y(t_data data, int y);
double	adjust_ray_x(t_data data, int x);
void	set_wall_hit(t_data *data, double x, double y, char sym);
double	get_wall_distance(t_data *data, char sym);
int		intercept_wall(t_data *data, double x, double y, char sym);

/* Player Movement */
void	set_player(t_data *data, t_map_requirements *var);
void	put_player(t_data *data);
double	player_move(t_data *data);
int		key_release(int key, t_data *data);
int		key_press(int key, t_data *data);

#endif