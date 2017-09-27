/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:23:31 by paperrin          #+#    #+#             */
/*   Updated: 2017/09/27 03:47:14 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		fract_tree(t_app *app)
{
	clear_image(app, get_color(app->draw_buf.image, ft_color_rgb(0, 0, 0)));
	mlx_put_image_to_window(app->mlx.core, app->mlx.win
			, app->draw_buf.image, 0, 0);
}

void		if_error(void *ptr)
{
	if (!ptr)
		printf("ERROR\n");
}

void		print_array(t_array *array)
{
	t_array_it		i;

	printf("array[%ld]: ", array->size);
	i = array->begin;
	while (i < array->end)
	{
		printf("%d, ", (int)*i);
		i++;
	}
	printf("\n");
}

void		fract_tree_init(t_app *app)
{
	app->fract.f_fractal = &fract_tree;

	t_array		array;

	array = ft_array_init(NULL);

	ft_array_push_back(&array, (void*)1);
	ft_array_push_back(&array, (void*)3);
	ft_array_push_front(&array, (void*)0);
	ft_array_add(&array, 2, (void*)2);
	print_array(&array);
}


