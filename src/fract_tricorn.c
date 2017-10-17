/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_tricorn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 19:32:59 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/17 20:14:21 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fract_tricorn(t_app *app)
{
	core_mandel_julia(app, &compute_zc_mandelbrot);
	put_info(app);
}

void			fract_tricorn_init(t_app *app)
{
	app->fract.f_fractal = &fract_tricorn;
	app->f_debug_str = NULL;
	app->f_controls_str = NULL;
	app->fract.nb_iter = 50;
	app->fract.iter_step = 25;
	app->fract.max_iter = 300;
	app->fract.origin = ft_vec3ld(0, 0, 1);
	app->fract.base_size = ft_vec3ld(
		4 * ((float)app->width / app->height), 4, 0);
	app->fract.is_burning_ship = 0;
	app->fract.mouse_locked = 0;
	create_palette(app, app->fract.nb_iter);
	if (app->mlx.core)
		event_key_release(KC_R, app);
}
