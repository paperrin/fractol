/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 19:44:28 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/08 01:13:32 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
#include <pthread.h>
# include "libft.h"
# include "ft_color.h"
# include "ft_printf.h"
# include "ft_math.h"
# include "mlx.h"

# define X11_KEY_PRESS 2
# define X11_KEY_RELEASE 3
# define X11_BUTTON_PRESS 4
# define X11_BUTTON_RELEASE 5
# define X11_MOTION_NOTIFY 6
# define X11_DESTROY_NOTIFY 17

# define X11_NO_EVENT_MASK (0L)
# define X11_POINTER_MOTION_MASK (1L<<6)
# define X11_BUTTON_PRESS_MASK (1L<<2)
# define X11_BUTTON_RELEASE_MASK (1L<<3)
# define X11_KEY_PRESS_MASK (1L<<0)
# define X11_KEY_RELEASE_MASK (1L<<1)

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
int				event_wheel_down(int key, int x, int y, void *param);
int				event_wheel_up(int key, int x, int y, void *param);
int				event_mouse_motion(int key, int x, int y, void *param);
int				event_loop(void *param);
void			put_pixel(const t_app *app, t_vec2i pos
		, t_color_rgb rgb);
void			fract_mandelbrot(t_app *app);

long double		map_nb(int value, int input[2], long double output[2]);

#endif
