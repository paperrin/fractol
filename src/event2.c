/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 00:36:37 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/08 21:03:21 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				event_wheel_down(int key, int x, int y, void *param)
{
	t_app	*app;

	app = (t_app*)param;
	(void)key;
	(void)x;
	(void)y;
	return (0);
}

int				event_wheel_up(int key, int x, int y, void *param)
{
	t_app	*app;

	app = (t_app*)param;
	(void)key;
	(void)x;
	(void)y;
	return (0);
}
#include <stdio.h>
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

	app->fract.c_julia.r = (long double)2 / app->width * x - 1;
	app->fract.c_julia.i = (long double)2 / app->height * y - 1;
	(*app->fract.f_fractal)(app);
	return (0);
}
