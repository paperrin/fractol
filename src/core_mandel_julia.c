/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_mandel_julia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:05:18 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/11 16:35:03 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		iterate(t_app *app, t_vec2i screen_pos, t_complex c
		, t_f_compute_zc f_compute_zc)
{
	t_complex		old;
	t_complex		new;
	t_complex		sq;
	//t_color_rgb		color;
	int				iter;

	f_compute_zc(app, &new, &c);
	iter = -1;
	while (++iter < app->fract.nb_iter)
	{
		if (app->fract.is_burning_ship)
			new = (t_complex){fabs((double)new.r), fabs((double)new.i)};
		old = new;
		sq.r = old.r * old.r;
		sq.i = old.i * old.i;
		if ((sq.r + sq.i) > 4)
			break ;
		new.r = sq.r - sq.i + c.r;
		new.i = 2 * old.r * old.i + c.i;
	}
	/*
	color = ft_color_hsv_to_rgb(
			ft_color_hsv(360 / app->fract.nb_iter * iter % 360, 99
				, 99 * (iter < app->fract.nb_iter)));
	put_pixel(ft_vec3f(screen_pos.x, screen_pos.y, 0)
		, color
		, (void*)app);
	//*/
	//*
	put_pixel(ft_vec3f(screen_pos.x, screen_pos.y, 0)
		, iter == app->fract.nb_iter ? ft_color_rgb(0, 0, 0)
			: ft_color_rgba_to_rgb(app->fract.colors[iter % app->fract.nb_colors])
		, (void*)app);
	//*/
}

static void		*render_section(void *arg_v)
{
	t_complex		c_inc;
	t_complex		c;
	t_vec2i			screen_pos;
	t_thread_arg	*arg;

	arg = (t_thread_arg*)arg_v;
	c_inc.r = arg->app->fract.size.x / arg->app->width;
	c_inc.i = arg->app->fract.size.y / arg->app->height;
	c.i = (arg->app->fract.pos.y - arg->app->fract.size.y / 2)
		+ (c_inc.i * arg->start.y);
	screen_pos.y = arg->start.y - 1;
	while (++screen_pos.y < arg->start.y + arg->size.y)
	{
		c.r = (arg->app->fract.pos.x - arg->app->fract.size.x / 2)
			+ (c_inc.r * arg->start.x);
		screen_pos.x = arg->start.x - 1;
		while (++screen_pos.x < arg->start.x + arg->size.x)
		{
			iterate(arg->app, screen_pos, c, arg->f_compute_zc);
			c.r += c_inc.r;
		}
		c.i += c_inc.i;
	}
	return (NULL);
}

static void		fill_gap(t_thread_arg *arg)
{
	t_vec2i		bounds;

	bounds = ft_vec2i(arg->start.x + arg->size.x, arg->start.y + arg->size.y);
	if (bounds.x + SCREEN_DIV > arg->app->width)
		arg->size.x = arg->app->width - arg->start.x;
	if (bounds.y + SCREEN_DIV > arg->app->height)
		arg->size.y = arg->app->height - arg->start.y;
}

static void		join_threads_and_render(t_app *app, pthread_t *threads)
{
	int		i;

	i = -1;
	while (++i < SCREEN_DIV * SCREEN_DIV)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(app->mlx.core, app->mlx.win
			, app->draw_buf.image, 0, 0);
}

void			core_mandel_julia(t_app *app, t_f_compute_zc f_compute_zc)
{
	pthread_t		threads[SCREEN_DIV * SCREEN_DIV];
	t_thread_arg	args[SCREEN_DIV * SCREEN_DIV];
	t_vec2i			size;
	t_vec2i			pos;
	int				i;

	size = ft_vec2i(app->width / SCREEN_DIV, app->height / SCREEN_DIV);
	pos.y = 0;
	i = 0;
	while (pos.y < app->height - SCREEN_DIV + 1)
	{
		pos.x = 0;
		while (pos.x < app->width - SCREEN_DIV + 1)
		{
			args[i] = (t_thread_arg){app, pos, size, f_compute_zc};
			fill_gap(&args[i]);
			if (pthread_create(&threads[i], NULL, render_section, &args[i]))
				error("Could not create thread.");
			pos.x += size.x;
			i++;
		}
		pos.y += size.y;
	}
	join_threads_and_render(app, threads);
}
