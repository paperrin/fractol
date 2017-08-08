/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:11:06 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/08 02:24:32 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			(t_app *app)
{
	t_complex	c;
	t_complex	c_inc;
	t_complex	new;
	t_complex	old;
	t_color	color;
	int		max_iterations = 200;
	int		x, y, i;

	app->fract.power = 5;
	y = -1;
	c_inc = (t_complex){app->fract.size.x / app->width, app->fract.size.y / app->height};
	c.i = app->fract.pos.y - app->fract.size.y / 2;
	while (++y < app->height)
	{
		x = -1;
		c.r = app->fract.pos.x - app->fract.size.x / 2;
		while (++x < app->width)
		{
			new.r = 0;
			new.i = 0;
			i = -1;
			while (++i < max_iterations)
			{
				old = new;
				new.r = old.r * old.r - old.i * old.i + c.r;
				new.i = 2 * old.r * old.i + c.i;
				if ((old.r * old.r + old.i * old.i) > 4)
					break ;
			}
			//color = (t_color){255 % i * (i < max_iterations), 125 + 125 % i, 125 + i % 125};
			color = color_from_hsv(i % 360,100,100 * (i < max_iterations));
			put_pixel(app, (t_vec3ld){x, y, 0}, color);
			c.r += c_inc.r;
		}
		c.i += c_inc.i;
	}
	put_pixel(app, (t_vec3ld){400, 400, 0}, (t_color){255,0,0});
	mlx_put_image_to_window(app->mlx.core, app->mlx.win, app->draw_buf.image, 0, 0);
}
