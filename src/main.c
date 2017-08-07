/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 19:42:58 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/08 00:08:09 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		create_app(t_app *app, size_t width, size_t height
		, char *title)
{
	app->width = width;
	app->height = height;
	if (!(app->mlx.core = mlx_init()))
		return (0);
	if (!(app->mlx.win = mlx_new_window(app->mlx.core
					, width, height, title)))
		return (0);
	if (!(app->draw_buf.image = mlx_new_image(app->mlx.core, width, height)))
		destroy_app(app, EXIT_FAILURE);
	app->draw_buf.pixels = mlx_get_data_addr(
			app->draw_buf.image
			, &(app->draw_buf.bits_per_pixel)
			, &(app->draw_buf.bytes_width)
			, &(app->draw_buf.is_big_endian));
	event_key_down(15, app);
	return (1);
}

void			destroy_app(t_app *app, int exit_code)
{
	mlx_destroy_window(app->mlx.core, app->mlx.win);
	if (app->draw_buf.image)
		mlx_destroy_image(app->mlx.core, app->draw_buf.image);
	exit(exit_code);
}

int				main(void)
{
	t_app	app;

	if (!create_app(&app, 800, 800, "Fract'ol paperrin"))
		return (EXIT_FAILURE);
	mlx_mouse_hook(app.mlx.win, &event_mouse_pressed, &app);
	mlx_hook(app.mlx.win, 3, 0, &event_key_released, &app);
	mlx_hook(app.mlx.win, 2, 3, &event_key_down, &app);
	mlx_hook(app.mlx.win, );
	mlx_loop(app.mlx.core);
	return (EXIT_SUCCESS);
}
