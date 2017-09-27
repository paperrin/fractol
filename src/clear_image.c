/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:36:56 by paperrin          #+#    #+#             */
/*   Updated: 2017/09/26 17:06:22 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			clear_image(t_app *app, unsigned int color)
{
	int				i;
	int				j;

	j = -1;
	while (++j * 4 < app->draw_buf.bytes_width * app->height)
	{
		i = -1;
		while (++i < 3)
			app->draw_buf.pixels[j * 4 + i] = color >> (i * 8);
	}
}
