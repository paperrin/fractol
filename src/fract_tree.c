/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:23:31 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/11 17:59:49 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			branch(t_app *app, int l, float w, int it)
{
	const float		angle = app->fract.a_tree;
	const float		bend = app->fract.d_tree;
	const float		size_mult = 0.75;

	if (it >= app->fract.nb_iter)
		return ;

	ft_graph_translate(&app->g, 0, -l, 0);
	app->g.fill_rgba = app->fract.colors[it % app->fract.nb_colors];
	ft_graph_env_aaline(&app->g, ft_vec2i(0, l), ft_vec2i(0, 0), w);
	app->fract.nb_branches++;

	if (!ft_graph_push(&app->g))
		return ;
	ft_graph_rot_z(&app->g, -angle + bend);
	branch(app, l * size_mult, w - app->fract.branch_width, it + 1);
	ft_graph_pop(&app->g);

	if (!ft_graph_push(&app->g))
		return ;
	ft_graph_rot_z(&app->g, angle + bend);
	branch(app, l * size_mult, w - app->fract.branch_width, it + 1);
	ft_graph_pop(&app->g);
}

void		fract_tree(t_app *app)
{
	app->fract.branch_width = (app->fract.trunk_width - 0.5)
		/ app->fract.nb_iter;
	app->fract.nb_branches = 0;

	if (!ft_graph_push(&app->g))
		return ;
	ft_graph_translate(&app->g, app->width / 2 + app->fract.trunk_offset.x
		, app->height + app->fract.trunk_offset.y, 0);
	branch(app, app->fract.trunk_height, app->fract.trunk_width, 0);
	ft_graph_pop(&app->g);

	mlx_put_image_to_window(app->mlx.core, app->mlx.win
			, app->draw_buf.image, 0, 0);
	put_info(app);
	clear_image(app, ft_color_rgb(0, 0, 0));
}

static void	make_palette(t_app *app, int n)
{
	t_color_rgb		rgb;
	int				i;

	app->fract.nb_colors = n;
	app->fract.colors = malloc(sizeof(t_color_rgba) * n);
	i = -1;
	while (++i < n)
	{
		rgb = ft_color_hsv_to_rgb(ft_color_hsv(360 / n * i, 99, 80));
		app->fract.colors[i] = ft_color_rgba(rgb.r, rgb.g, rgb.b, 1);
	}
}

static char		*get_debug_str(t_app *app)
{
	char	*str;

	ft_asprintf(&str
		, "<F1> DEBUG ------------------------\n \n"
			" Iterations:   %4d\n"
			" Nb branches: %5d\n"
			" Trunk height: %4d\n"
			" Trunk width: %2d\n"
			" \n"
		, app->fract.nb_iter, app->fract.nb_branches
		, app->fract.trunk_height, app->fract.trunk_width);
	return (str);
}

static char		*get_controls_str()
{
	return (
	"<F2> CONTROLS ---------------------\n \n"
	" Change fractal: number keys 1 to 4\n"
	" Move: <UP> <DOWN> <LEFT> <RIGHT>\n"
	" Fractal parameter (option): mouse movement\n"
	" Lock/Unlock fractal parameter: L\n"
	" Change iterations: [ & ]\n"
	" Quit: <ESC>");
}

void			fract_tree_init(t_app *app)
{
	clear_image(app, ft_color_rgb(0, 0, 0));
	app->fract.f_fractal = &fract_tree;
	app->f_debug_str = &get_debug_str;
	app->f_controls_str = &get_controls_str;
	app->fract.d_tree = 0;
	app->fract.a_tree = M_PI / 5;
	app->fract.nb_iter = 10;
	app->fract.iter_step = 1;
	app->fract.max_iter = 16;
	app->fract.trunk_offset = ft_vec2i(0, 0);
	app->fract.trunk_height = 180;
	app->fract.trunk_width = 5;
	app->fract.mouse_locked = 0;
	ft_graph_env_init(&app->g, &put_pixel, &put_pixel_rgba, app);
	make_palette(app, 14);
}
