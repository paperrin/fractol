/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 19:44:28 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/07 23:18:04 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft.h"
# include "ft_color.h"
# include "ft_printf.h"
# include "ft_math.h"
# include "mlx.h"

typedef struct		s_mlx_image
{
	void	*image;
	char	*pixels;
	int		bits_per_pixel;
	int		bytes_width;
	int		is_big_endian;
}					t_mlx_image;

typedef struct		s_mlx
{
	void			*core;
	void			*win;
}					t_mlx;

typedef struct		s_complex
{
	long double		r;
	long double		i;
}					t_complex;

typedef struct		s_fract
{
	t_vec3ld			pos;
	t_vec3ld			size;
	int					max_iter;
}					t_fract;

typedef struct		s_app
{
	t_mlx			mlx;
	t_mlx_image		draw_buf;
	int				width;
	int				height;
	t_fract			fract;

}					t_app;

typedef struct		s_thread_arg
{
	t_app		*app;
	t_vec2i		start;
	t_vec2i		size;
}					t_thread_arg;

void			destroy_app(t_app *app, int exit_code);
int				event_key_pressed(int key, void *param);
int				event_key_released(int key, void *param);
int				event_key_down(int key, void *param);
int				event_mouse_pressed(int key, int x, int y, void *param);
int				event_loop(void *param);
void			put_pixel(const t_app *app, t_vec2i pos
		, t_color_rgb rgb);
void			fract_mandelbrot(t_app *app);

long double		map_nb(int value, int input[2], long double output[2]);

#endif
