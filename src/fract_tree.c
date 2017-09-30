/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:23:31 by paperrin          #+#    #+#             */
/*   Updated: 2017/09/30 04:37:16 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fract_tree(t_app *app)
{
	const size_t	n = 3;
	t_vec3f			v[n];
	t_color_rgb		c[n];
	t_array			*edge_table;

	int		h;

	h = app->height - 100;

	v[0] = ft_vec3f(app->width / 2, 50, 0);	c[0] = ft_color_rgb(255, 0, 0);
	v[1] = ft_vec3f(app->width / 2 + h / 2, 50 + h, 0);	c[1] = ft_color_rgb(0, 255, 0);
	v[2] = ft_vec3f(app->width / 2 - h / 2, 50 + h, 0);	c[2] = ft_color_rgb(0, 0, 255);
	if (!(edge_table = ft_graph_create_edge_table(v, c, n)))
		exit(1);

	clear_image(app, get_color(app->draw_buf.image, ft_color_rgb(0, 0, 0)));

	if (!ft_graph_poly_fill(edge_table, &put_pixel, (void*)app))
		exit(1);

	mlx_put_image_to_window(app->mlx.core, app->mlx.win
			, app->draw_buf.image, 0, 0);
}

void		fract_tree_init(t_app *app)
{
	app->fract.f_fractal = &fract_tree;
}


