/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:36:56 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/21 18:57:01 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			clear_image(t_app *app, t_color_rgb color)
{
	unsigned int	encoded;
	int				i;
	int				j;

	if (!app->draw_buf.image)
		return ;
	encoded = get_color(app->draw_buf.image, color);
	j = -1;
	while (++j * 4 < app->draw_buf.bytes_width * app->height)
	{
		i = -1;
		while (++i < 3)
			app->draw_buf.pixels[j * 4 + i] = encoded >> (i * 8);
	}
	i = -1;
	while (++i < app->width * app->height)
		app->draw_buf.colors[i] = color;
}
