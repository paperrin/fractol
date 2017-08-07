/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 17:52:57 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/06 17:59:03 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double		map_nb(int value, int input[2], long double output[2])
{
	long double		scale_factor;
	long double		input_diff;

	input_diff = (input[1] - input[0]);
	if (input_diff == 0)
		input_diff = 0.0001;
	scale_factor = (output[1] - output[0]) / input_diff;
	return (output[0] + (long double)value * scale_factor);
}
