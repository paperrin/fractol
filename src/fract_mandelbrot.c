/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:12:05 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/08 23:06:47 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			compute_zc_mandelbrot(t_app *app, t_complex *z, t_complex *c)
{
	(void)app;
	(void)c;
	z->r = 0;
	z->i = 0;
}

void			fract_mandelbrot(t_app *app)
{
	core_mandel_julia(app, &compute_zc_mandelbrot);
}

void			fract_mandelbrot_init(t_app *app)
{
	app->fract.f_fractal = fract_mandelbrot;
	app->fract.max_iter = 100;
	app->fract.origin = ft_vec3ld(-.6, 0, 1);
	app->fract.base_size = ft_vec3ld(4, 4, 0);
	app->fract.is_burning_ship = 0;
	app->fract.mouse_locked = 0;
	event_key_release(KC_R, app);
}
