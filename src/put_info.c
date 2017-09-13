/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 10:32:04 by paperrin          #+#    #+#             */
/*   Updated: 2017/09/13 11:04:55 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		put_string_to_screen(t_app *app, t_point point, char *str)
{
	char	**str_lines;
	int		line_nb;

	if (!(str_lines = ft_strsplit(str, '\n')))
		return ;
	line_nb = -1;
	while (str_lines[++line_nb])
	{
		mlx_string_put(app->mlx.core, app->mlx.win
				, point.pos.x, point.pos.y + line_nb * 16
				, get_color(app->mlx.core, point.color)
				, str_lines[line_nb]);
	}
	ft_strsplit_free(str_lines);
}

static char		*get_debug_string(int should_print)
{
	if (!should_print)
		return ("<F1> DEBUG\n");
	else
		return (
		"<F1> DEBUG ------------------------\n \n"
		" Iterations: %4d\n \n");
}

static char		*get_controls_string(int should_print)
{
	if (!should_print)
		return ("<F2> CONTROLS");
	else
		return (
		"<F2> CONTROLS ---------------------\n \n"
		" Change fractal: number keys 1 to 3\n"
		" Move: <UP> <DOWN> <LEFT> <RIGHT>\n"
		" Fractal parameter (option): mouse movement\n"
		" Lock/Unlock fractal parameter: L\n"
		" Zoom: + & -\n"
		" Change iterations: [ & ]\n"
		" Reset view: R\n"
		" Quit: <ESC>");
}

void			put_info(t_app *app)
{
	t_point		point;
	char		*str;
	char		*format;

	format = ft_strjoin(get_debug_string(app->show_debug)
			, get_controls_string(app->show_controls));
	if (!format)
		return ;
	ft_asprintf(&str, format, app->fract.max_iter);
	free(format);
	if (!str)
		return ;
	point.pos = ft_vec2i(7, 2);
	point.color = ft_color_rgb(0, 0, 0);
	put_string_to_screen(app, point, str);
	point.pos = ft_vec2i(5, 0);
	point.color = ft_color_rgb(255, 255, 255);
	put_string_to_screen(app, point, str);
	free(str);
}
