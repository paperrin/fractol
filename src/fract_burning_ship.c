/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_burning_ship.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:05:28 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/12 13:20:10 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fract_burning_ship_init(t_app *app)
{
	app->fract.f_fractal = fract_mandelbrot;
	app->f_debug_str = NULL;
	app->f_controls_str = NULL;
	app->fract.nb_iter = 50;
	app->fract.iter_step = 25;
	app->fract.max_iter = 300;
	app->fract.origin = ft_vec3ld(-.4, -.6, 1);
	app->fract.base_size = ft_vec3ld(4, 4, 0);
	app->fract.is_burning_ship = 1;
	app->fract.mouse_locked = 0;
	create_palette(app, app->fract.nb_iter);
	if (app->mlx.core)
		event_key_release(KC_R, app);
}
