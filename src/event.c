/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 20:18:42 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/06 22:03:14 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			event_key_down(int key, void *param)
{
	t_app	*app;
	float	speed;

	app = (t_app*)param;
	speed = 0.2;
	if (key == 24)
		app->fract.pos.z *= 1.2;
	else if (key == 27)
		app->fract.pos.z /= 1.2;
	else if (key == 13)
		app->fract.pos.y -= speed / app->fract.pos.z;
	else if (key == 0)
		app->fract.pos.x -= speed / app->fract.pos.z;
	else if (key == 1)
		app->fract.pos.y += speed / app->fract.pos.z;
	else if (key == 2)
		app->fract.pos.x += speed / app->fract.pos.z;
	else if (key == 15)
	{
		app->fract.pos = ft_vec3d(-0.6, 0, 1);
		app->fract.size = ft_vec3d(4, 4, 0);
	}
	app->fract.size = (t_vec3d){4 / app->fract.pos.z, 4 / app->fract.pos.z, 0};
	draw_julia(app);
	return (0);
}


#include <stdio.h>
int			event_mouse_pressed(int key, int x, int y, void *param)
{
	t_app		*app;
	t_vec3d		clicked;

	app = (t_app*)param;
	clicked.x = map_nb(x, (int[2]){0, app->width - 1}
			, (double[2]){app->fract.pos.x - app->fract.size.x / 2
				, app->fract.pos.x + app->fract.size.x / 2});
	clicked.y = map_nb(y, (int[2]){0, app->height - 1}
			, (double[2]){app->fract.pos.y - app->fract.size.y / 2
				, app->fract.pos.y + app->fract.size.y / 2});
	if (key == 1)
	{
		app->fract.pos = (t_vec3d){clicked.x + (app->fract.pos.x - clicked.x) / 1.2, clicked.y + (app->fract.pos.y - clicked.y) / 1.2
			, app->fract.pos.z * 1.2};
		app->fract.size = (t_vec3d){4 / app->fract.pos.z, 4 / app->fract.pos.z, 0};
		draw_julia(app);
	}
	return (0);
}

int			event_key_released(int key, void *param)
{
	if (key == 53)
		destroy_app((t_app*)param, EXIT_SUCCESS);
	return (0);
}
