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

double		map_nb(int value, int input[2], double output[2])
{
	double		scale_factor;
	double		input_diff;

	input_diff = (input[1] - input[0]);
	if (input_diff == 0)
		input_diff = 1;
	scale_factor = (output[1] - output[0]) / input_diff;
	return (output[0] + (double)value * scale_factor);
}
