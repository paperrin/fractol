/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 00:36:37 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/08 23:03:15 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				event_mouse_press(int key, int x, int y, void *param)
{
	t_app	*app;

	app = (t_app*)param;
	(void)key;
	(void)x;
	(void)y;
	if (key == BC_LEFT || key == BC_RIGHT
			|| key == BC_WHEEL_UP || key == BC_WHEEL_DOWN)
		zoom(app, ft_vec2i(x, y), 1.2, key == BC_LEFT || key == BC_WHEEL_UP);
	return (0);
}

int				event_mouse_release(int key, int x, int y, void *param)
{
	t_app	*app;

	app = (t_app*)param;
	(void)key;
	(void)x;
	(void)y;
	return (0);
}

int				event_mouse_motion(int x, int y, void *param)
{
	t_app	*app;

	app = (t_app*)param;
	if (x < 0)
		x = 0;
	else if (x >= app->width)
		x = app->width - 1;
	if (y < 0)
		y = 0;
	else if (y >= app->height)
		y = app->height - 1;

	if (!app->fract.mouse_locked)
	{
		app->fract.c_julia.r = (long double)2 / app->width * x - 1;
		app->fract.c_julia.i = (long double)2 / app->height * y - 1;
		(*app->fract.f_fractal)(app);
	}
	return (0);
}
