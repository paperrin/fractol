/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_palette.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:44:59 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/12 13:10:50 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_palette(t_app *app, int n)
{
	t_color_rgb		rgb;
	int				i;

	app->fract.nb_colors = n;
	if (app->fract.colors)
		free(app->fract.colors);
	if (!(app->fract.colors = malloc(sizeof(t_color_rgba) * n)))
		error("Could not allocate color palette.");
	i = -1;
	while (++i < n)
	{
		rgb = ft_color_hsv_to_rgb(ft_color_hsv(360 / n * i, 89, 80));
		app->fract.colors[i] = ft_color_rgba(rgb.r, rgb.g, rgb.b, 1);
	}
}
