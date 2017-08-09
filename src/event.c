/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 20:18:42 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/09 20:29:12 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			event_key_down(int key, void *param)
{
	t_app	*app;
	float	speed;

	app = (t_app*)param;
	speed = 0.2;
	if (key == KC_ADD || key == KC_SUBTRACT)
		zoom(app, ft_vec2i(app->width / 2, app->height / 2), 1.2
				, key == KC_ADD);
	else if (key == KC_W)
		app->fract.pos.y -= speed / app->fract.pos.z;
	else if (key == KC_A)
		app->fract.pos.x -= speed / app->fract.pos.z;
	else if (key == KC_S)
		app->fract.pos.y += speed / app->fract.pos.z;
	else if (key == KC_D)
		app->fract.pos.x += speed / app->fract.pos.z;
	(*app->fract.f_fractal)(app);
	return (0);
}

int			event_key_release(int key, void *param)
{
	t_app		*app;

	app = (t_app*)param;
	if (key == KC_ESCAPE)
		destroy_app((t_app*)param, EXIT_SUCCESS);
	else if (key == KC_L)
		app->fract.mouse_locked = !app->fract.mouse_locked;
	else if (key == KC_1 || key == KC_2 || key == KC_3)
		init_fractal(app, NULL, key);
	else if (key == KC_R)
	{
		app->fract.pos = app->fract.origin;
		app->fract.size = app->fract.base_size;
		app->fract.size = (t_vec3ld){4 / app->fract.pos.z
			, 4 / app->fract.pos.z, 0};
	}
	(*app->fract.f_fractal)(app);
	return (0);
}

void		zoom(t_app *app, t_vec2i pos, float ammount, int is_zoom_in)
{
	t_vec3ld		clicked;

	if (pos.y < 0)
		return ;
	ammount = (is_zoom_in ? ammount : 1 / ammount);
	clicked.x = map_nb(pos.x, (int[2]){0, app->width - 1}
			, (long double[2]){app->fract.pos.x - app->fract.size.x / 2
			, app->fract.pos.x + app->fract.size.x / 2});
	clicked.y = map_nb(pos.y, (int[2]){0, app->height - 1}
			, (long double[2]){app->fract.pos.y - app->fract.size.y / 2
			, app->fract.pos.y + app->fract.size.y / 2});
	app->fract.pos = (t_vec3ld){clicked.x + (app->fract.pos.x - clicked.x)
		* (1 / ammount), clicked.y + (app->fract.pos.y - clicked.y)
			* (1 / ammount), app->fract.pos.z * ammount};
	app->fract.size = (t_vec3ld){4 / app->fract.pos.z, 4 / app->fract.pos.z, 0};
	(*app->fract.f_fractal)(app);
}
