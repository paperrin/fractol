/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 19:44:28 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/04 11:11:38 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "ft_color.h"
# include "ft_printf.h"
# include "ft_math.h"
# include "ft_array.h"
# include "ft_graph.h"
# include "mlx.h"
# include "X11.h"

# define SCREEN_DIV 5

typedef struct			s_mlx_image
{
	void	*image;
	char	*pixels;
	int		bits_per_pixel;
	int		bytes_width;
	int		is_big_endian;
}						t_mlx_image;

typedef struct			s_mlx
{
	void	*core;
	void	*win;
}						t_mlx;

typedef struct			s_complex
{
	long double		r;
	long double		i;
}						t_complex;

typedef struct s_app	t_app;

typedef void			(*t_f_fractal)(t_app *app);

typedef struct			s_fract
{
	t_vec3ld		pos;
	t_vec3ld		size;
	int				max_iter;
	t_complex		c_julia;
	int				is_burning_ship;
	t_f_fractal		f_fractal;
	t_vec3ld		origin;
	t_vec3ld		base_size;
	int				mouse_locked;
}						t_fract;

struct					s_app
{
	t_mlx			mlx;
	t_mlx_image		draw_buf;
	t_graph_env		g;
	int				width;
	int				height;
	t_fract			fract;
	int				show_controls;
	int				show_debug;
	t_vec2i			mouse_pos;
};

typedef void			(*t_f_compute_zc)(t_app *app
		, t_complex *z, t_complex *c);

typedef struct			s_thread_arg
{
	t_app			*app;
	t_vec2i			start;
	t_vec2i			size;
	t_f_compute_zc	f_compute_zc;
}						t_thread_arg;

typedef struct		s_point
{
	t_vec2i			pos;
	t_color_rgb		color;
}					t_point;

void					destroy_app(t_app *app, int exit_code);
int						event_key_press(int key, void *param);
int						event_key_release(int key, void *param);
int						event_key_down(int key, void *param);
int						event_mouse_press(int key, int x, int y, void *param);
int						event_mouse_release(int key, int x, int y, void *param);
int						event_mouse_motion(int x, int y, void *param);
int						event_loop(void *param);
void					put_pixel(t_vec3f pos, t_color_rgb rgb
	, void *app);

void					zoom(t_app *app, t_vec2i pos, float ammount
		, int is_zoom_in);

void					core_mandel_julia(t_app *app
		, t_f_compute_zc f_compute_zc);

void					fract_mandelbrot_init(t_app *app);
void					fract_mandelbrot(t_app *app);
void					compute_zc_mandelbrot(t_app *app
		, t_complex *z, t_complex *c);

void					fract_julia_init(t_app *app);
void					fract_julia(t_app *app);
void					compute_zc_julia(t_app *app
		, t_complex *z, t_complex *c);

void					fract_burning_ship_init(t_app *app);

void					fract_tree_init(t_app *app);
void					fract_tree(t_app *app);

void					error(char *error);
void					usage(char *error);
t_f_fractal				init_fractal(t_app *app, char *name, int kc);
int						parse_args(int ac, char **av, t_app *app);
unsigned int			get_color(void *mlx_core, t_color_rgb color);
void					put_info(t_app *app);
void					clear_image(t_app *app, unsigned int color);

long double				map_nb(int value, int input[2], long double output[2]);

#endif
