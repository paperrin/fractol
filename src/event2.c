/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 00:36:37 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/08 02:22:35 by paperrin         ###   ########.fr       */
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

int				event_mouse_motion(int key, int x, int y, void *param)
{
	t_app	*app;

	app = (t_app*)param;
	(void)key;
	(void)x;
	(void)y;
	return (0);
}
