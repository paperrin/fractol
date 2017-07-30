/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 19:42:58 by paperrin          #+#    #+#             */
/*   Updated: 2017/07/30 20:02:53 by paperrin         ###   ########.fr       */
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
	app->pos = (t_vec3f){0,0,1};
	return (1);
}

void			destroy_app(t_app *app, int exit_code)
{
	mlx_destroy_window(app->mlx.core, app->mlx.win);
	if (app->draw_buf.image)
		mlx_destroy_image(app->mlx.core, app->draw_buf.image);
	exit(exit_code);
}

static t_color	color_from_hsv(int h, int s, int v)
{
	int				ti;
	float			l;
	float			m;
	float			n;
	t_color		color;

	ti = (h / 60) % 6;
	l = (v * (1.f - s));
	m = (v * (1.f - (h / 60.f - ti) * s));
	n = (v * (1.f - (1.f - (h / 60.f - ti)) * s));
	if (ti == 0)
		color = (t_color){(int)v, (int)n, (int)l};
	else if (ti == 1)
		color = (t_color){(int)m,(int)v,(int)l};
	else if (ti == 2)
		color = (t_color){(int)l,(int)v,(int)n};
	else if (ti == 3)
		color = (t_color){(int)l,(int)m,(int)v};
	else if (ti == 4)
		color = (t_color){(int)n,(int)l,(int)v};
	else
		color = (t_color){(int)v,(int)l,(int)m};
	return (color);
}

/*void			draw_julia(t_app *app)
{
	double	c_re = -0.7, c_im = 0.27015;
	double	new_re, new_im, old_re, old_im;
	t_color	color;
	int		max_iterations = 50;
	int		w = 800, h = 800;
	int		x, y, i;

	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
		{
			new_re = (1.5 * (x - w / 2) / (0.5 * app->pos.z * w)) + app->pos.x / 400;
			new_im = (y - h / 2) / (0.5 * app->pos.z * h) - app->pos.y / 400;
			i = -1;
			while (++i < max_iterations)
			{
				old_re = new_re;
				old_im = new_im;
				new_re = old_re * old_re - old_im * old_im + c_re;
				new_im = 2 * old_re * old_im + c_im;
				if ((new_re * new_re + new_im * new_im) > 4)
					break ;
			}
			color = color_from_hsv(i % 361,100,100 * (i < max_iterations));
			put_pixel(app, (t_vec3f){x, y, 0}, color);
		}
	}
	mlx_put_image_to_window(app->mlx.core, app->mlx.win, app->draw_buf.image, 0, 0);
}*/

void			draw_julia(t_app *app)
{
	double	p_re, p_im;
	double	new_re, new_im, old_re, old_im;
	t_color	color;
	int		max_iterations = 300;
	int		x, y, i;

	y = -1;
	while (++y < app->height)
	{
		x = -1;
		while (++x < app->width)
		{
			p_re = 1.5 * ((x - app->width / 2) / (0.5 * app->pos.z * app->width) + app->pos.x / 400) - 0.5;
			p_im = (y - app->height / 2) / (0.5 * app->pos.z * app->height) - app->pos.y / 400;
			new_re = 0;
			new_im = 0;
			i = -1;
			while (++i < max_iterations)
			{
				old_re = new_re;
				old_im = new_im;
				new_re = old_re * old_re - old_im * old_im + p_re;
				new_im = 2 * old_re * old_im + p_im;
				if ((new_re * new_re + new_im * new_im) > 4)
					break ;
			}
			color = color_from_hsv(i % 361,100,100 * (i < max_iterations));
			put_pixel(app, (t_vec3f){x, y, 0}, color);
		}
	}
	put_pixel(app, (t_vec3f){400, 400, 0}, (t_color){255,0,0});
	mlx_put_image_to_window(app->mlx.core, app->mlx.win, app->draw_buf.image, 0, 0);
}

int				main(void)
{
	t_app	app;

	if (!create_app(&app, 800, 800, "Fract'ol paperrin"))
		return (EXIT_FAILURE);
	draw_julia(&app);
	mlx_mouse_hook(app.mlx.win, &event_mouse_pressed, &app);
	mlx_hook(app.mlx.win, 3, 0, &event_key_released, &app);
	mlx_hook(app.mlx.win, 2, 3, &event_key_down, &app);
	mlx_loop(app.mlx.core);
	return (EXIT_SUCCESS);
}
