/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 19:42:58 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/19 16:29:12 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		create_app(t_app *app, size_t width, size_t height
		, char *title)
{
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
	if (!(app->draw_buf.colors = (t_color_rgb*)ft_memalloc(
		sizeof(t_color_rgb) * width * height)))
		destroy_app(app, EXIT_FAILURE);
	app->show_debug = 0;
	app->show_controls = 0;
	event_key_release(KC_R, app);
	return (1);
}

void			destroy_app(t_app *app, int exit_code)
{
	mlx_destroy_window(app->mlx.core, app->mlx.win);
	if (app->draw_buf.image)
		mlx_destroy_image(app->mlx.core, app->draw_buf.image);
	exit(exit_code);
}

int				main(int ac, char **av)
{
	t_app	app;

	app.fract.colors = NULL;
	app.mlx.core = NULL;
	app.draw_buf.image = NULL;
	app.f_debug_str = NULL;
	app.f_controls_str = NULL;
	app.width = 700;
	app.height = 700;
	app.g = NULL;
	if (!parse_args(ac, av, &app))
		return (EXIT_FAILURE);
	if (!create_app(&app, app.width, app.height, "Fract'ol paperrin"))
		return (EXIT_FAILURE);
	mlx_hook(app.mlx.win, X11_KEY_RELEASE, 0, &event_key_release, &app);
	mlx_hook(app.mlx.win, X11_KEY_PRESS, 0, &event_key_down, &app);
	mlx_hook(app.mlx.win, X11_BUTTON_PRESS, 0, &event_mouse_press, &app);
	mlx_hook(app.mlx.win, X11_BUTTON_RELEASE, 0, &event_mouse_release, &app);
	mlx_hook(app.mlx.win, X11_MOTION_NOTIFY, 0, &event_mouse_motion, &app);
	mlx_loop(app.mlx.core);
	return (EXIT_SUCCESS);
}
