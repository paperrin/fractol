/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 20:18:42 by paperrin          #+#    #+#             */
/*   Updated: 2017/07/30 16:27:36 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			event_key_down(int key, void *param)
{
	t_app	*app;
	float	speed;

	app = (t_app*)param;
	speed = 0.1;
	ft_printf("KEY_DOWN %d\n", key);

	if (key == 24)
		app->pos.z *= 1.5;
	else if (key == 27)
		app->pos.z /= 2;
	else if (key == 13)
		app->pos.y -= speed / app->pos.z;
	else if (key == 0)
		app->pos.x -= speed / app->pos.z;
	else if (key == 1)
		app->pos.y += speed / app->pos.z;
	else if (key == 2)
		app->pos.x += speed / app->pos.z;

	draw_julia(app);

	return (0);
}

int			event_key_released(int key, void *param)
{
	ft_printf("KEY_RELEASED %d\n", key);
	if (key == 53)
		destroy_app((t_app*)param, EXIT_SUCCESS);
	return (0);
}
