/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 19:45:17 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/09 20:22:50 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			compute_zc_julia(t_app *app, t_complex *z, t_complex *c)
{
	(void)app;
	z->r = c->r;
	z->i = c->i;
	c->r = app->fract.c_julia.r;
	c->i = app->fract.c_julia.i;
}

void			fract_julia(t_app *app)
{
	core_mandel_julia(app, &compute_zc_julia);
}

void			fract_julia_init(t_app *app)
{
	app->fract.f_fractal = fract_julia;
	app->fract.max_iter = 50;
	app->fract.origin = ft_vec3ld(0, 0, 1);
	app->fract.c_julia = (t_complex){0, 0};
	app->fract.origin = ft_vec3ld(0, 0, 1);
	app->fract.base_size = ft_vec3ld(4, 4, 0);
	app->fract.is_burning_ship = 0;
	app->fract.mouse_locked = 0;
	if (app->mlx.core)
		event_key_release(KC_R, app);
}