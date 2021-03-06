/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 18:50:10 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/19 16:35:25 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				error(char *error)
{
	if (error)
	{
		ft_putstr_fd("error: ", STDOUT_FILENO);
		ft_putendl_fd(error, STDOUT_FILENO);
	}
	exit(EXIT_FAILURE);
}

void				usage(char *error)
{
	if (error)
	{
		ft_putstr_fd("error: ", STDOUT_FILENO);
		ft_putendl_fd(error, STDOUT_FILENO);
	}
	ft_putstr("usage: ./fractol [mandelbrot|julia|"
		"tricorn|burning_ship|tree]\n");
	exit(EXIT_FAILURE);
}

static t_f_fractal	check_init_fractal(t_app *app, char *name
	, t_f_fractal f_fractal)
{
	if (f_fractal)
		(*f_fractal)(app);
	else if (name)
		usage("Invalid fractal name.");
	return (f_fractal);
}

t_f_fractal			init_fractal(t_app *app, char *name, int kc)
{
	static const int		size = 5 * 3;
	static void				*fractals[size] = {
		(void*)"mandelbrot", (void*)KC_1, (void*)&fract_mandelbrot_init,
		(void*)"julia", (void*)KC_2, (void*)&fract_julia_init,
		(void*)"tricorn", (void*)KC_3, (void*)&fract_tricorn_init,
		(void*)"burning_ship", (void*)KC_4, (void*)&fract_burning_ship_init,
		(void*)"tree", (void*)KC_5, (void*)&fract_tree_init};
	t_f_fractal				f_fractal;
	int						i;

	f_fractal = NULL;
	i = -3;
	while ((i += 3) < size)
	{
		if (kc == (int)fractals[i + 1])
			f_fractal = (t_f_fractal)fractals[i + 2];
		else if (name && !ft_strcmp(name, fractals[i]))
			f_fractal = (t_f_fractal)fractals[i + 2];
	}
	return (check_init_fractal(app, name, f_fractal));
}

int					parse_args(int ac, char **av, t_app *app)
{
	if (ac > 1)
	{
		if (!init_fractal(app, av[1], -1))
			fract_mandelbrot_init(app);
	}
	else
		fract_mandelbrot_init(app);
	return (1);
}
