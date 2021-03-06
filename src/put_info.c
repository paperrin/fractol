/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 10:32:04 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/21 20:33:04 by paperrin         ###   ########.fr       */
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

static char		*get_debug_string(t_app *app)
{
	static const char	*state[2] = {"UNLOCKED", "LOCKED"};
	char				*str;

	if (!app->show_debug)
		str = ft_strdup("<F1> DEBUG\n");
	else
	{
		if (app->f_debug_str)
			str = (*app->f_debug_str)((void*)app);
		else
		{
			ft_asprintf(&str
				, "<F1> DEBUG ------------------------\n \n"
					" Iterations: %7d\n"
					" Parameter: %8s\n \n"
				, app->fract.nb_iter
				, state[app->fract.mouse_locked]);
		}
	}
	return (str);
}

static char		*get_controls_string(t_app *app)
{
	if (!app->show_controls)
		return ("<F2> CONTROLS");
	else
	{
		if (app->f_controls_str)
			return ((*app->f_controls_str)());
		else
		{
			return (
			"<F2> CONTROLS ---------------------\n \n"
			" Change fractal: number keys 1 to 5\n"
			" Move: W A S D\n"
			" Fractal parameter (option): mouse movement\n"
			" Lock/Unlock fractal parameter: L\n"
			" Zoom: + & -, mouse click or mousewheel\n"
			" Decr/Incr iterations: [ & ]\n"
			" Reset view: R\n"
			" Quit: <ESC>");
		}
	}
}

void			put_info(t_app *app)
{
	t_point		point;
	char		*debug_str;
	char		*str;

	if (!(debug_str = get_debug_string(app)))
		return ;
	str = ft_strjoin(debug_str, get_controls_string(app));
	if (!str || !debug_str)
	{
		if (str)
			free(str);
		if (debug_str)
			free(debug_str);
		return ;
	}
	point.pos = ft_vec2i(7, 2);
	point.color = ft_color_rgb(0, 0, 0);
	put_string_to_screen(app, point, str);
	point.pos = ft_vec2i(5, 0);
	point.color = ft_color_rgb(255, 255, 255);
	put_string_to_screen(app, point, str);
	free(str);
}
