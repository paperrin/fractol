/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 14:39:45 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/06 18:27:56 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static unsigned int		get_color(void *mlx_core, t_color color)
{
	int		encoded;

	encoded = 0;
	encoded |= color.b;
	encoded |= color.g << 8;
	encoded |= color.r << 16;
	return (mlx_get_color_value(mlx_core, encoded));
}

void					put_pixel(const t_app *app
		, const t_vec3d pos, const t_color color_rgb)
{
	size_t			index;
	unsigned int 	color_encoded;
	int				i;

	color_encoded = get_color(app->mlx.core, color_rgb);
	index = ((pos.y * app->draw_buf.bytes_width) + (pos.x * 4));
	i = -1;
	while (++i < 3)
		app->draw_buf.pixels[index + i] = color_encoded >> (i * 8);
}
