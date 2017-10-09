/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:23:31 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/09 06:11:41 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			branch(t_app *app, int l, float w)
{
	const float		angle = M_PI / 3;
	const float		size_mult = 0.7;

	ft_graph_translate(&app->g, 0, -l + w / 2 - 1, 0);
	ft_graph_env_aaline(&app->g, ft_vec2i(0, l), ft_vec2i(0, 0), w);

	if (w < 0.5)
		return ;

	if (!ft_graph_push(&app->g))
		return ;
	ft_graph_rot_z(&app->g, -angle);
	branch(app, l * size_mult, w - 1);
	ft_graph_pop(&app->g);

	if (!ft_graph_push(&app->g))
		return ;
	ft_graph_rot_z(&app->g, angle);
	branch(app, l * size_mult, w - 1);
	ft_graph_pop(&app->g);
}

void		fract_tree(t_app *app)
{
	clear_image(app, get_color(app->draw_buf.image, ft_color_rgb(0, 0, 0)));

	ft_graph_push(&app->g);
	ft_graph_translate(&app->g, app->width / 2, app->height - 50, 0);
	branch(app, 200, 11);
	ft_graph_pop(&app->g);

	mlx_put_image_to_window(app->mlx.core, app->mlx.win
			, app->draw_buf.image, 0, 0);
}

void		fract_tree_init(t_app *app)
{
	app->fract.f_fractal = &fract_tree;
	ft_graph_env_init(&app->g, &put_pixel, app);
}
