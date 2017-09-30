/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:23:31 by paperrin          #+#    #+#             */
/*   Updated: 2017/09/30 00:53:23 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		fract_tree(t_app *app)
{
	const size_t	n = 4;
	t_vec3f			v[n];
	t_color_rgb		c[n];
	t_array			*edge_table;

	v[0] = ft_vec3f(5, 5, 0);	c[0] = ft_color_rgb(255, 255, 255);
	v[1] = ft_vec3f(50, 5, 0);	c[0] = ft_color_rgb(255, 255, 255);
	v[2] = ft_vec3f(100, 100, 0);	c[0] = ft_color_rgb(255, 255, 255);
	v[3] = ft_vec3f(5, 100, 0);	c[0] = ft_color_rgb(255, 255, 255);
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


