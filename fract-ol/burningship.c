/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:03:42 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/25 00:05:37 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_burning_ship_fractal(t_list *data)
{
	int		x;
	int		y;
	double	z_real;
	double	z_imag;
	int		iterations;

	declare(data);
	y = 0;
	while (++y < HEIGHT)
	{
		x = 0;
		while (++x < WIDTH)
		{
			data->center_real2 = ((x - WIDTH / 2.0) * 4.0 / WIDTH)
				/ data->zoom + data->center_real;
			data->center_imag2 = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT)
				/data->zoom + data->center_imag;
			z_real = 0.0;
			z_imag = 0.0;
			iterations = 0;
			iterations = iterate(iterations, data, &z_real, &z_imag);
			colour(data, iterations, x, y);
		}
	}
}
