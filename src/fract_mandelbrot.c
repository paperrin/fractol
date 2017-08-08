/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:12:05 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/08 02:24:29 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		iterate(t_app *app, t_vec2i screen_pos, t_complex c)
{
	t_complex		old;
	t_complex		new;
	t_color_rgb		color;
	int				iter;

	new.r = 0;
	new.i = 0;
	iter = -1;
	while (++iter < app->fract.max_iter)
	{
		old = new;
		new.r = old.r * old.r - old.i * old.i + c.r;
		new.i = 2 * old.r * old.i + c.i;
		if ((old.r * old.r + old.i * old.i) > 4)
			break ;
	}
	//color = ft_color_rgb(255 % i * (i < max_iterations), 125 + 125 % i, 125 + i % 125);
	color = ft_color_hsv_to_rgb(
	ft_color_hsv(360 / app->fract.max_iter * iter, 99, 99 * (iter < app->fract.max_iter))
	);
	put_pixel(app, screen_pos, color);
}

static void		*render_section(void *arg_v)
{
	t_complex		c_inc;
	t_complex		c;
	t_vec2i			screen_pos;
	t_thread_arg	*arg;

	arg = (t_thread_arg*)arg_v;
	arg->app->fract.max_iter = 100;
	c_inc.r = arg->app->fract.size.x / arg->app->width;
	c_inc.i = arg->app->fract.size.y / arg->app->height;
	c.i = (arg->app->fract.pos.y - arg->app->fract.size.y / 2) + (c_inc.i * arg->start.y);
	screen_pos.y = arg->start.y - 1;
	while (++screen_pos.y < arg->start.y + arg->size.y)
	{
		c.r = (arg->app->fract.pos.x - arg->app->fract.size.x / 2) + (c_inc.r * arg->start.x);
		screen_pos.x = arg->start.x - 1;
		while (++screen_pos.x < arg->start.x + arg->size.x)
		{
			iterate(arg->app, screen_pos, c);
			c.r += c_inc.r;
		}
		c.i += c_inc.i;
	}
	return (NULL);
}

static int		fill_gap(t_thread_arg *arg, int div)
{
	t_vec2i		bounds;

	bounds = ft_vec2i(arg->start.x + arg->size.x, arg->start.y + arg->size.y);
	if (bounds.x + div > arg->app->width)
		arg->size.x = arg->app->width - arg->start.x;
	if (bounds.y + div > arg->app->height)
		arg->size.y = arg->app->height - arg->start.y;
	return (bounds.x > arg->app->width || bounds.y > arg->app->width);
}

void			fract_mandelbrot(t_app *app)
{
	const int		div = 3;
	pthread_t		threads[div * div];
	t_thread_arg	args[div * div];
	int				ret[div * div];
	t_vec2i			size;
	t_vec2i			pos;
	int				i;

	size = ft_vec2i(app->width / div, app->height / div);
	pos.y = 0;
	i = 0;
	while (pos.y < app->height - div + 1)
	{
		pos.x = 0;
		while (pos.x < app->width - div + 1)
		{
			args[i] = (t_thread_arg){app, pos, size};
			fill_gap(&args[i], div);
			ret[i] = pthread_create(&threads[i], NULL, render_section, args + i);
			pos.x += size.x;
			i++;
		}
		pos.y += size.y;
	}//*/
	i = -1;
	while (++i < div * div)
	{
		pthread_join(threads[i], NULL);
	}//*/
	mlx_put_image_to_window(app->mlx.core, app->mlx.win, app->draw_buf.image, 0, 0);
}
