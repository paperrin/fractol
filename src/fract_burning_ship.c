/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_burning_ship.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 22:05:28 by paperrin          #+#    #+#             */
/*   Updated: 2017/09/13 11:07:49 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fract_burning_ship_init(t_app *app)
{
	app->fract.f_fractal = fract_mandelbrot;
	app->fract.max_iter = 50;
	app->fract.origin = ft_vec3ld(-.4, -.6, 1);
	app->fract.base_size = ft_vec3ld(4, 4, 0);
	app->fract.is_burning_ship = 1;
	app->fract.mouse_locked = 0;
	if (app->mlx.core)
		event_key_release(KC_R, app);
}
