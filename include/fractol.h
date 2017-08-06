/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 19:44:28 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/06 19:18:45 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft.h"
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
	double			r;
	double			i;
}					t_complex;

typedef struct		s_fract
{
	t_vec3d			pos;
	t_vec3d			size;
}					t_fract;

typedef struct		s_app
{
	t_mlx			mlx;
	t_mlx_image		draw_buf;
	int				width;
	int				height;
	t_fract			fract;

}					t_app;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

void		destroy_app(t_app *app, int exit_code);
int			event_key_pressed(int key, void *param);
int			event_key_released(int key, void *param);
int			event_key_down(int key, void *param);
int			event_mouse_pressed(int key, int x, int y, void *param);
int			event_loop(void *param);
void		put_pixel(const t_app *app, const t_vec3d pos
		, const t_color color_rgb);
void		draw_julia(t_app *app);

double		map_nb(int value, int input[2], double output[2]);

#endif
