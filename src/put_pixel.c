/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 14:39:45 by paperrin          #+#    #+#             */
/*   Updated: 2017/09/30 00:04:06 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int			get_color(void *mlx_core, t_color_rgb color)
{
	int		encoded;

	encoded = 0;
	encoded |= color.b;
	encoded |= color.g << 8;
	encoded |= color.r << 16;
	return (mlx_get_color_value(mlx_core, encoded));
}

void					put_pixel(t_vec3f pos, t_color_rgb rgb, void *app)
{
	size_t			index;
	unsigned int	color_encoded;
	int				i;

	color_encoded = get_color(((t_app*)app)->mlx.core, rgb);
	index = (((int)pos.y * ((t_app*)app)->draw_buf.bytes_width)
		+ ((int)pos.x * 4));
	i = -1;
	while (++i < 3)
		((t_app*)app)->draw_buf.pixels[index + i] = color_encoded
			>> (i * 8);
}
